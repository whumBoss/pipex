/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 20:56:23 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_arguments *pipex, int j, int tab_pid[2], int i)
{
	tab_pid[i] = fork();
	if (tab_pid[i] == 0)
	{
		if (pipex->path[j] &&
			execve(pipex->path[j], pipex->cmd[j], pipex->envp) == -1)
		{
			close_files(pipex);
			free_all(pipex);
			ft_printf("Pipex error, shell command: %s\n", strerror(errno));
			exit(errno);
		}
	}
	return (0);
}

//REDIRECTION POUR QUE CHILD1 ECRIVE DANS PIPE[1]
//EXECUTION CMD1
//EXECUTION DE LA CMD2 SI LE INFILE ET OUTFILE EST VALIDE
//REDIRECTION POUR QUE CHILD2 LISE DANS PIPE[0]
//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
//EXECUTION CMD2
void	exec_cmd1(t_arguments *pipex, int p[2], int tab_pid[2], int *i)
{
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	child(pipex, 0, tab_pid, *i);
	(*i)++; // ou *i++; ??????
	if (pipex->cmd[1] != NULL)
	{
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		close(pipex->fd_outfile);
		child(pipex, 1, tab_pid, *i);
	}

}

//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
//EXECUTION CMD2
void	exec_cmd2(t_arguments *pipex, int tab_pid[2], int *i)
{
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	close(pipex->fd_outfile);
	child(pipex, 1, tab_pid, *i);
}

// FAIRE LA REDIRECTION DE L'INFILE
// CREER LE PIPE
void	creat_pipe(t_arguments *pipex, int p[2])
{
	if (pipex->fd_infile != 0)
	{
		dup2(pipex->fd_infile, STDIN_FILENO);
		close(pipex->fd_infile);
	}
	if (pipe(p) < 0)
	{
		ft_printf("Pipex error, pipe creation : %s\n", strerror(errno));
		close_files(pipex);
		free_all(pipex);
		exit(1);
	}
}

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

	tab_pid[0] = -1;
	tab_pid[1] = -1;
	i = 0;
	status = 0;
	// else
	// 	(void)p;
	if (pipex->cmd[0] == NULL && pipex->cmd[1] == NULL)
		no_cmd(pipex);
	if (pipex->cmd[0] && pipex->cmd[1])
	{
		if (pipex->fd_infile > 0)
			creat_pipe(pipex, p);
		exec_cmd1(pipex, p, tab_pid, &i);
	}
	else if (pipex->cmd[0] == NULL && pipex->cmd[1] != NULL)
		exec_cmd2(pipex, tab_pid, &i);
	
	ft_printf("i= %d", i);
	ft_printf("pid0= %d\n", tab_pid[0]);
	ft_printf("pid1= %d\n", tab_pid[1]);
	
	waitpid(tab_pid[0], &status, 0);
	// int j = 0;
	// while (j <= i)
	// {
	// 	j++;
	// }
	free_all(pipex);
	close_files(pipex);
	free(pipex);
	exit(status);
}
// mauvaise utilisation de status??????