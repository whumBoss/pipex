/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wissalhumeau <wissalhumeau@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:05:43 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/04 21:47:58 by wissalhumea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

	// ON RECUPRERE LA LIGNE 
	// SI ARGC != 5)
	// 	ERREUR

void	init(t_arg *pipex, char **env)
{
	ft_bzero(pipex, sizeof(t_arg));
	pipex->env = env;
	pipex->cmd1.fdinput = -1;
	pipex->cmd1.fdoutput = -1;
	pipex->cmd2.fdinput = -1;
	pipex->cmd2.fdoutput = -1;
	pipex->pipe[0] = -1;
	pipex->pipe[1] = -1;
}

int		main(int ac, char **av, char **env)
{
	int		i = 0;
	t_arg	*pipex;

	pipex = calloc(1, sizeof(t_arg));
	if (!pipex)
		return (1);
	if (ac != 5)
	{
		ft_printf("Expected ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	init(pipex, env);
	parsing(pipex, av);
	ft_printf("TEST DU PARSING\n\n");
	ft_printf("pipex->infile : %s\n", pipex->infile);
	ft_printf("pipex->outfile : %s\n", pipex->outfile);
	ft_printf("pipex->pipe[2] : %d et %d\n\n", pipex->pipe[0], pipex->pipe[1]);
	ft_printf("pipex->env :\n");
	while (pipex->env[i])
	{
		ft_printf("%s\n", pipex->env[i]);
		i++;
	}
	ft_printf("\npipex->cmd1 :\ncmd1->cmd :\n");
	i = 0;
	while (pipex->cmd1.cmd[i])
	{
		ft_printf("%s\n", pipex->cmd1.cmd[i]);
		i++;
	}
	ft_printf("\ncmd1->path : %s\n", pipex->cmd1.path);
	ft_printf("cmd1->fdinput : %d\n", pipex->cmd1.fdinput);
	ft_printf("cmd1->fdoutput : %d\n\n", pipex->cmd1.fdoutput);
	ft_printf("pipex->cmd2 :\ncmd2->cmd\n");
	i = 0;
	while (pipex->cmd2.cmd[i])
	{
		ft_printf("%s\n", pipex->cmd2.cmd[i]);
		i++;
	}
	ft_printf("\ncmd2->path : %s\n", pipex->cmd2.path);
	ft_printf("cmd2->fdinput : %d\n", pipex->cmd2.fdinput);
	ft_printf("cmd2->fdinput : %d\n\n", pipex->cmd2.fdoutput);
	ft_printf("FIN DU TEST\n");
	return (0);
}