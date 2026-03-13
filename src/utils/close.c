/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibras <tibras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/13 16:08:18 by tibras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closePipex(t_arg *pipex)
{
	if (pipex->cmd1.fdinput >= 0)
		close(pipex->cmd1.fdinput);
	if (pipex->pipe[0] >= 0)
		close(pipex->pipe[0]);
	if (pipex->pipe[1] >= 0)
		close(pipex->pipe[1]);
	if (pipex->cmd2.fdoutput >= 0)
		close(pipex->cmd2.fdoutput);
}

void	closeCmd(t_cmd *cmd)
{
	if (cmd->fdinput >= 0)
		close(cmd->fdinput);
	if (cmd->fdoutput >= 0)
		close(cmd->fdoutput);
}

void	closeFiles(t_arg *pipex)
{
	if (pipex->cmd1.fdinput >= 0)
		close(pipex->cmd1.fdinput);
	if (pipex->cmd2.fdoutput >= 0)
		close(pipex->cmd2.fdoutput);
}