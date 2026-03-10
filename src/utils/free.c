/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:18:11 by wissalhumea       #+#    #+#             */
/*   Updated: 2026/03/10 18:08:31 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_paths(char **complete_cmd, char ***path_tab)
{
	free(*complete_cmd);
	free_tab(*path_tab);
}

void	freePipex(t_arg *pipex)
{
	free_tab(pipex->cmd1.args);
	free_tab(pipex->cmd2.args);
	free(pipex->cmd1.path);
	free(pipex->cmd2.path);
	free(pipex);
}

void	freeCmd(t_cmd *cmd)
{
	free(cmd->path);
	free_tab(cmd->args);
}