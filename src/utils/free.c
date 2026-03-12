/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:18:11 by wissalhumea       #+#    #+#             */
/*   Updated: 2026/03/12 16:39:17 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]); // invalid free parent et child
		i++;
	}
	free(tab); // invalid free child
}

void	free_paths(char *complete_cmd, char **path_tab)
{
	free(complete_cmd);
	free_tab(path_tab);
}

void	freePipex(t_arg *pipex)
{
	free_tab(pipex->cmd1.args); // invalid free parent et child
	free_tab(pipex->cmd2.args); // invalid free child
	//free(pipex->cmd1.path); // invalid free parent et child
	free(pipex->cmd2.path);
	free(pipex);
}

void	freeCmd(t_cmd *cmd)
{
	free(cmd->path); // invalid free child
	free_tab(cmd->args); // invalid free child
}