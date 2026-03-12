/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:10:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/12 16:20:17 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*EXECUTION

		INITIALISER UN TABLEAU DE PID = pid[2]
		CREER UNE PREMIERE FORK

			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

			GERER LES REDIRECTIONS

				INITALISER IN_FD ET OUT_FD

				AFFECTER A  CMD.IN_FD -> INFILE_FD SI 1ER CHILD
				AFFECTER A  CMD.OUT_FD -> PIPE[0] SI 1ER CHILD

			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
			DUP2(INFILEFD, STDIN)
			DUP2(OUTFILEFD, STDOUT)
			FERMER TOUT LE RESTE

			CREER L'EXECUTIION

				FAIRE PASSER  DANS EXECVE
				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

		CREER UNE DEUXIEME FORK

			FORMATER CHILD EN FONCTION DE SA POSITION (1ER OU 2EME)

				GERER LES REDIRECTIONS

				INITALISER IN_FD ET OUT_FD

				AFFECTER A  IN_FD -> PIPE[1] SI 2EME CHILD
				AFFECTER A  OUT_FD -> OUTFILE_FD SI 2EME CHILD

			SI ERREUR (IN_FD < 0 OU OUT_FD < 0)
				ERREUR (FREE ET EXIT) /!\ ON EST TOUJOUR DANS UN CHILD
			DUP2(INFILEFD, STDIN)
			DUP2(OUTFILEFD, STDOUT)
			FERMER TOUT LE RESTE

			CREER L'EXECUTIION

				FAIRE PASSER  DANS EXECVE
				GERER LES CAS D'ERREURS OU EXECVE ECHOUE

	PENDANT CE TEMPS LA DANS LE PARENT :

		ON COMMENCE PAR TOUT FERMER
		ON ATT POUR LES 2 PROCESSUS DE SE TERMINER
		ON AFFECTE A STATUS LA VALEUR DE RETOUR DE LA DERNIERE COMMANDE RECU PAR WAITPID
		ON RETURN
		*/

/* CORRECTION EXEC

	child
faire une seule fonction child
Le child 1 ecris dans le pipe[1] (2e case du tab)
Le child 2 lis dans le pipe[0] (1e case du tab)
utiliser un pointeur vers la structure cmd
tjrs close avant de free
pas besoin de condition pour execve
utiliser closePipex pour TOUT close avant execve (les pipes n'etais pas close donc le child ne fini jamais, on wait dans le vide)

	parent
Modif la boucle waitpid pour recuperer uniquement le status du dernier child
Macro qui verifi le status... Necessaire pour valider pipex ou peut attendre minishell??

	general
Verif si j'ai d'autres fonctions generique que je pourrais transformer en une
Attention au utilisation de pointeur, notamment dans la fonction free_path, pas besoin de pointeur de pointeur de...
/!\ TESTER CHAQUE FONCTION AVANT DE CONTINUER A CODER /!\
*/

int		child(t_arg *pipex, t_cmd *cmd)
{
	if (cmd->args == pipex->cmd1.args)
		cmd->fdoutput = pipex->pipe[1];
	if (cmd->args == pipex->cmd2.args)
		cmd->fdinput = pipex->pipe[0];
	if (cmd->fdinput < 0 || cmd->fdoutput < 0)
	{
		closePipex(pipex);
		closeCmd(cmd);
		freePipex(pipex);
		freeCmd(cmd);
		exit(1); // exit code pour ce cas d'erreur???
	}
	dup2(cmd->fdinput, STDIN_FILENO);
	dup2(cmd->fdoutput, STDOUT_FILENO);
	closePipex(pipex);
	closeCmd(cmd);
	execve(cmd->path, cmd->args, pipex->env);
	freePipex(pipex); // invalid free
	freeCmd(cmd); // invalid free
	exit(errno); // exit code pour ce cas d'erreur???
}

void	exec(t_arg *pipex)
{
	int		j = 0;
	int		tab_pid[2];
	int		status;

	tab_pid[0] = -1;
	tab_pid[1] = -1;

	if (pipe(pipex->pipe) < 0)
	{
		ft_printf("Pipex error, pipe creation : %s\n", strerror(errno));
		closeFiles(pipex);
		freePipex(pipex);
		exit(1);
	}
	tab_pid[0] = fork();
	if (tab_pid[0] == 0)
		child(pipex, &pipex->cmd1);
	tab_pid[1] = fork();
	if (tab_pid[1] == 0)
		child(pipex, &pipex->cmd2);
	closePipex(pipex);
	freePipex(pipex); // 2 invalid free
	while (j <= 1)
	{
		if (j == 1)
			waitpid(tab_pid[j], &status, 0);
		else
			waitpid(tab_pid[j], NULL, 0);
		j++;
	}
	// macro verif le status
	exit(status);
}