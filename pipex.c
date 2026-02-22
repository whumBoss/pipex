/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/22 17:59:44 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_arguments pipex, int j, int tab_pid[2], int i)
{
	tab_pid[i] = fork();
	
	if (tab_pid[i] == 0)
	{
		if (execve(pipex.path[j], pipex.cmd[j], pipex.envp) == -1)
		{
			close_files(pipex);
			free_all(pipex);
			ft_printf("Erreur pipex, commande shell: %s\n", strerror(errno));
			exit(127);
		}
	}
	else
		(void)pipex;
	return (0);
}

//free, close et terminer le programme car pas de cmd
void	no_cmd(t_arguments pipex, int p[2])
{
	ft_printf("Erreur pipex : aucune commande a executer\n");
	close_pipe(p);
	free_all(pipex);
	close_files(pipex);
	exit(1);
}

//REDIRECTION POUR QUE CHILD1 ECRIVE DANS PIPE[1]
//EXECUTION CMD1
//EXECUTION DE LA CMD2 SI LE INFILE ET OUTFILE EST VALIDE
//REDIRECTION POUR QUE CHILD2 LISE DANS PIPE[0]
//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
//EXECUTION CMD2
int	exec_cmd1(t_arguments pipex, int p[2], int tab_pid[2], int i)
{
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	child(pipex, 0, tab_pid, i);
	i++;
	if (pipex.cmd[1] != NULL)
	{
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		dup2(pipex.fd_outfile, STDOUT_FILENO);
		close(pipex.fd_outfile);
		child(pipex, 1, tab_pid, i);
	}
	return (i);
}

//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
//EXECUTION CMD2
int	exec_cmd2(t_arguments pipex, int tab_pid[2], int i)
{
	dup2(pipex.fd_outfile, STDOUT_FILENO);
	close(pipex.fd_outfile);
	child(pipex, 1, tab_pid, i);
	return (i);
}

// FAIRE LA REDIRECTION DE L'INFILE
// CREER LE PIPE
void	creat_pipe(t_arguments pipex, int p[2])
{
	{
		dup2(pipex.fd_infile, STDIN_FILENO);
		close(pipex.fd_infile);
	}
	if (pipe(p) < 0)
	{
		ft_printf("Erreur pipex, creation du pipe : %s\n", strerror(errno));
		close_files(pipex);
		free_all(pipex);
		//free(pipex);
		exit(1);
	}
}

//REDIRECTION POUR QUE CHILD1 LISE DANS INFILE et CREATION DU PIPE
//VERIF SI IL Y A DES CMD A EXECUTER
//EXECUTION DE LA CMD1 SI LE INFILE EST VALIDE
//EXECUTION CMD2 SI LE OUTFILE EST VALIDE ET LE INFILE INVALIDE
//WAIT POUR LE PREMIER PID ET SI IL Y EN A 2 WAIT POUR LE 2E AUSSI
//CLEAN TOUT AVANT D'EXIT
void	parent(t_arguments pipex)
{
	int	tab_pid[2] = {0, 0};
	int	i = 0;
	int	p[2];
	int	status;
	
	if (pipex.fd_infile > 0)
		creat_pipe(pipex, p);
	else
		(void)p;
	if (pipex.cmd[0] == NULL && pipex.cmd[1] == NULL)
		no_cmd(pipex, p);
	if (pipex.cmd[0] != NULL)
		exec_cmd1(pipex, p, tab_pid, i); // j'ai besoin de faire i = ...?
	else if (pipex.cmd[0] == NULL && pipex.cmd[1] != NULL)
		exec_cmd2(pipex, tab_pid, i); // j'ai besoin de faire i = ...?
	waitpid(tab_pid[0], &status, 0);
	if (i == 1)
		waitpid(tab_pid[1], &status, 0);
	free_all(pipex);
	close_files(pipex);
	exit(WEXITSTATUS(status));
}
//fonction close all pour fermer tout les fd ---> pas vraiment necessaire dans mon cas
//FONCTION POUR FREE TOUT : ---> reste des leak, flags valgrind????
// WAIT!!!! 
// --> bug: exit code tjrs 0 meme si les cmd ne sont pas valable

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		t_arguments	pipex;
		pipex = parsing(argv, envp);
		parent(pipex);
	}
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