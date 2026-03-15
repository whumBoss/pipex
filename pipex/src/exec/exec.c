/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:10:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/15 21:07:02 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

// EXECUTION

// 		INITIALISER UN TABLEAU DE PID = pid[2]
// 		CREER UNE PREMIERE FORK

// 			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

// 			GERER LES REDIRECTIONS

// 				INITALISER IN_FD ET OUT_FD

// 				AFFECTER A  CMD.IN_FD -> INFILE_FD SI 1ER CHILD
// 				AFFECTER A  CMD.OUT_FD -> PIPE[0] SI 1ER CHILD

// 			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
// 				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
// 			DUP2(INFILEFD, STDIN)
// 			DUP2(OUTFILEFD, STDOUT)
// 			FERMER TOUT LE RESTE

// 			CREER L'EXECUTIION

// 				FAIRE PASSER  DANS EXECVE
// 				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

// 		CREER UNE DEUXIEME FORK

// 			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

// 				GERER LES REDIRECTIONS

// 				INITALISER IN_FD ET OUT_FD

// 				AFFECTER A  IN_FD -> PIPE[1] SI 2EME CHILD
// 				AFFECTER A  OUT_FD -> OUTFILE_FD SI 2EME CHILD

// 			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
// 				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
// 			DUP2(INFILEFD, STDIN)
// 			DUP2(OUTFILEFD, STDOUT)
// 			FERMER TOUT LE RESTE

// 			CREER L'EXECUTIION

// 				FAIRE PASSER  DANS EXECVE
// 				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

// 	PENDANT CE TEMPS LA DANS LE PARENT :

// 		ON COMMENCE PAR TOUT FERMER
// 		ON ATT POUR LES 2 PROCESSUS DE SE TERMINER
// 		ON AFFECTE A STATUS LA VALEUR DE RETOUR DE 
// 		LA DERNIERE COMMANDE RECU PAR WAITPID
// 		ON RETURN
//
//  CORRECTION EXEC

// 	child
// faire une seule fonction child
// Le child 1 ecris dans le pipe[1] (2e case du tab)
// Le child 2 lis dans le pipe[0] (1e case du tab)
// utiliser un pointeur vers la structure cmd
// tjrs close avant de free
// pas besoin de condition pour execve
// utiliserclose_pipex pour TOUT close avant execve 
// (les pipes n'etais pas close donc le child ne fini jamais,
// on wait dans le vide)

// 	parent
// Modif la boucle waitpid pour recuperer uniquement le status du dernier child
// Macro qui verifi le status...
// Necessaire pour valider pipex ou peut attendre minishell??

// 	general
// Verif si j'ai d'autres fonctions generique que je pourrais transformer en une
// Attention au utilisation de pointeur, notamment dans la fonction free_path,
// pas besoin de pointeur de pointeur de...
// /!\ TESTER CHAQUE FONCTION AVANT DE CONTINUER A CODER /!\
//

// RAJOUT DE ERROR POUR EXIT AVEC CODE ERREUR
static void	error_pipe(t_arg *pipex, int error)
{
	close_pipex(pipex);
	free_pipex(pipex);
	perror("Pipex");
	exit(error);
}

// MODIFICATION DE LA FONCTION POUR RECUPERER WAITPID DANS LA BOUCLE DIRECTEMENT
// NE PAS FREE LA STRUCTURE AVANT DE COMPARER PID AVEC TAB_PID[i]
static void	waiting(t_arg *pipex)
{
	pid_t	pid;
	int		count;
	int		status;
	int		exit_code;

	exit_code = 0;
	count = 0;
	while (count < 2)
	{
		pid = waitpid(0, &status, 0);
		if (pid == pipex->tab_pid[1])
			exit_code = status;
		count++;
	}
	free_pipex(pipex);
	if (WIFEXITED(exit_code))
		exit(WEXITSTATUS(exit_code));
	exit(1);
}

int	child(t_arg *pipex, t_cmd *cmd)
{
	if (!cmd->path && cmd->args && cmd->args[0])
		cmd->path = ft_strdup(cmd->args[0]);
	if (cmd->args == pipex->cmd1.args)
		cmd->fdoutput = pipex->pipe[1];
	if (cmd->args == pipex->cmd2.args)
		cmd->fdinput = pipex->pipe[0];
	if (cmd->fdinput < 0 || cmd->fdoutput < 0)
		error_pipe(pipex, 1);
	dup2(cmd->fdinput, STDIN_FILENO);
	dup2(cmd->fdoutput, STDOUT_FILENO);
	close_pipex(pipex);
	if (!cmd || !cmd->args || !cmd->args[0] || !cmd->args[0][0] || !cmd->path)
	{
		error_pipe(pipex, 127);
	}
	execve(cmd->path, cmd->args, pipex->env);
	perror("Pipex");
	free_pipex(pipex);
	if (errno == EACCES)
		exit(126);
	exit(127);
}

void	exec(t_arg *pipex)
{
	if (pipe(pipex->pipe) < 0)
		error_pipe(pipex, 1);
	pipex->tab_pid[0] = fork();
	if (pipex->tab_pid[0] == -1)
		perror("fork");
	if (pipex->tab_pid[0] == 0)
		child(pipex, &pipex->cmd1);
	pipex->tab_pid[1] = fork();
	if (pipex->tab_pid[1] == -1)
		perror("fork");
	if (pipex->tab_pid[1] == 0)
		child(pipex, &pipex->cmd2);
	close_pipex(pipex);
	waiting(pipex);
}
