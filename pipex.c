/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/16 21:49:29 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		//char	*path = find_path(argv[1], envp);
		//char	**cmd = ft_split(argv[1], ' ');
		// ASSIGNER MES COMMANDES DANS UNE LISTE CHAINEE
		parsing(argc, argv, envp);
		// EXECUTER UNE COMMANDE SHELL
		execve(path, cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	// int i = 0;
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	pipex(argc, argv, envp);
}
