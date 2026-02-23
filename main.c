/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:10:31 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/23 21:16:06 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//REDIRECTION POUR QUE CHILD1 LISE DANS INFILE et CREATION DU PIPE
//VERIF SI IL Y A DES CMD A EXECUTER
//EXECUTION DE LA CMD1 SI LE INFILE EST VALIDE
//EXECUTION CMD2 SI LE OUTFILE EST VALIDE ET LE INFILE INVALIDE
//WAIT POUR LE PREMIER PID ET SI IL Y EN A 2 WAIT POUR LE 2E AUSSI
//CLEAN TOUT AVANT D'EXIT
// VU QUE PREMIERE COMMANDe, PAS DE BESOIN DE GARDER LE STATUS

void	parent(t_arguments *pipex)
{
	int	tab_pid[2];
	int	i;
	int	p[2];
	int	status;

	tab_pid = {0, 0};
	i = 0;
	if (pipex->fd_infile > 0)
		creat_pipe(pipex, p);
	else
		(void)p;
	if (pipex->cmd[0] == NULL && pipex->cmd[1] == NULL)
		no_cmd(pipex, p);
	if (pipex->cmd[0] != NULL)
		exec_cmd1(pipex, p, tab_pid, &i);
	else if (pipex->cmd[0] == NULL && pipex->cmd[1] != NULL)
		exec_cmd2(pipex, tab_pid, &i);
	waitpid(tab_pid[0], NULL, 0);
	if (i == 1)
		waitpid(tab_pid[1], &status, 0);
	free_all(pipex);
	close_files(pipex);
	exit(WEXITSTATUS(status));
}

//fonction close all pour fermer tout les fd
// ---> pas vraiment necessaire dans mon cas
//FONCTION POUR FREE TOUT :
// ---> reste des leak, flags valgrind????
// WAIT!!!! 
// --> bug: exit code tjrs 0 meme si les cmd ne sont pas valable

int	main(int argc, char **argv, char **envp)
{
	t_arguments	pipex;

	if (argc == 5)
		parent(&pipex);
	else if (argc > 5)
		ft_printf("Pipex error : too many arguments, expected 5.\n");
	else if (argc < 5)
		ft_printf("Pipex error : not enough arguments, expected 5.\n");
	return (0);
}

// CAS LIMITES
// < infileNonexist cat | ls > outfileExist  || Deuxieme commande executer
// < infileExist cat | ls > outfileNonexist  || Le outfile est creer

// STDINFILENO 0
// STDOUTFILENO 1