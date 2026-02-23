/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/23 21:13:05 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(t_arguments *pipex, int j, int tab_pid[2], int i)
{
	tab_pid[i] = fork();
	if (tab_pid[i] == 0)
	{
		if (execve(pipex->path[j], pipex->cmd[j], pipex->envp) == -1)
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
void	no_cmd(t_arguments *pipex, int p[2])
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
void	exec_cmd1(t_arguments *pipex, int p[2], int tab_pid[2], int *i)
{
	dup2(p[1], STDOUT_FILENO);
	close(p[1]);
	child(pipex, 0, tab_pid, i);
	*i++;
	if (pipex->cmd[1] != NULL)
	{
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		close(pipex->fd_outfile);
		child(pipex, 1, tab_pid, i);
	}
}

//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
//EXECUTION CMD2
void	exec_cmd2(t_arguments *pipex, int tab_pid[2], int *i)
{
	dup2(pipex->fd_outfile, STDOUT_FILENO);
	close(pipex->fd_outfile);
	child(pipex, 1, tab_pid, i);
}

// FAIRE LA REDIRECTION DE L'INFILE
// CREER LE PIPE
void	creat_pipe(t_arguments *pipex, int p[2])
{
	{
		dup2(pipex->fd_infile, STDIN_FILENO);
		close(pipex->fd_infile);
	}
	if (pipe(p) < 0)
	{
		ft_printf("Erreur pipex, creation du pipe : %s\n", strerror(errno));
		close_files(pipex);
		free_all(pipex);
		exit(1);
	}
}
