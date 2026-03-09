/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wissalhumeau <wissalhumeau@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:10:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/09 20:34:52 by wissalhumea      ###   ########.fr       */
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
int		child2(t_arg *pipex, int tab_pid[2])
{
	pipex->cmd2.fdinput = pipex->pipe[1];
	if (pipex->cmd1.fdinput < 0 || pipex->cmd1.fdoutput < 0)
	{
		freePipex(pipex);
		close(pipex);
		exit(1); // exit code pour ce cas d'erreur???
	}
	dup2(pipex->cmd2.fdinput, STDIN_FILENO);
	close(pipex->cmd2.fdinput);
	dup2(pipex->cmd2.fdoutput, STDOUT_FILENO);
	close(pipex->cmd2.fdoutput);
	if(execve(pipex->cmd2.path, pipex->cmd2.args, pipex->env) == -1);
	{
		freePipex(pipex);
		closeChild2(pipex);
		exit(errno); // exit code pour ce cas dérreur???
	}
	// est ce que je dois return une valeur jsp comment je fait pour recup le status?
}

int		child1(t_arg *pipex, int tab_pid[2])
{
	pipex->cmd1.fdoutput = pipex->pipe[0];
	if (pipex->cmd1.fdinput < 0 || pipex->cmd1.fdoutput < 0)
	{
		freePipex(pipex);
		close(pipex);
		exit(1); // exit code pour ce cas d'erreur???
	}
	dup2(pipex->cmd1.fdinput, STDIN_FILENO);
	close(pipex->cmd1.fdinput);
	dup2(pipex->cmd1.fdoutput, STDOUT_FILENO);
	close(pipex->cmd1.fdoutput);
	if(execve(pipex->cmd1.path, pipex->cmd1.args, pipex->env) == -1);
	{
		freePipex(pipex);
		closeChild1(pipex);
		exit(errno); // exit code pour ce cas dérreur???
	}
	// est ce que je dois return une valeur jsp comment je fait pour recup le status?
}

void	exec(t_arg *pipex)
{
	int		j = 0;
	int		tab_pid[2];

	tab_pid[0] = -1;
	tab_pid[1] = -1;

	if (pipe(pipex->pipe) < 0)
	{
		ft_printf("Pipex error, pipe creation : %s\n", strerror(errno));
		freePipex(pipex);
		closeFiles(pipex)
		exit(1);
	}
	tab_pid[0] = fork();
	if (tab_pid[0] == 0)
		child1(pipex, tab_pid);
	tab_pid[1] = fork();
	if (tab_pid[1] == 0)
		child2(pipex, tab_pid);
	freePipex(pipex);
	closePipex(pipex);
	while (j <= i)
	{
		waitpid(tab_pid[j], &status, 0);
		j++;
	}
	exit(status);
}