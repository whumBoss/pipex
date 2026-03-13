/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:05:43 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/13 21:48:55 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	pipex->tab_pid[0] = -1;
	pipex->tab_pid[1] = -1;
}

int	main(int ac, char **av, char **env)
{
	t_arg	*pipex;

	pipex = calloc(1, sizeof(t_arg));
	if (!pipex)
		return (1);
	if (ac != 5)
	{
		free_pipex(pipex);
		ft_printf("Expected ./pipex file1 cmd1 cmd2 file2\n");
		return (0);
	}
	init(pipex, env);
	parsing(pipex, av);
	exec(pipex);
	return (0);
}

// ft_printf("TEST DU PARSING\n\n");
	// ft_arg_print(pipex, 0);
	// ft_cmd_print(&pipex->cmd1, 1);
	// ft_cmd_print(&pipex->cmd2, 2);
	// ft_printf("FIN DU TEST\n");