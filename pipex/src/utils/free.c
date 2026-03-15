/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:18:11 by wissalhumea       #+#    #+#             */
/*   Updated: 2026/03/15 20:29:28 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_paths(char *complete_cmd, char **path_tab)
{
	free(complete_cmd);
	free_tab(path_tab);
}

void	free_pipex(t_arg *pipex)
{
	if (pipex->cmd1.args)
		free_tab(pipex->cmd1.args);
	if (pipex->cmd2.args)
		free_tab(pipex->cmd2.args);
	if (pipex->cmd1.path)
		free(pipex->cmd1.path);
	if (pipex->cmd2.path)
		free(pipex->cmd2.path);
	if (pipex)
		free(pipex);
}

void	free_cmd(t_cmd *cmd)
{
	free(cmd->path);
	free_tab(cmd->args);
}
