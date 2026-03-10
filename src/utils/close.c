/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:44:50 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/10 18:16:29 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closePipex(t_arg *pipex)
{
	close(pipex->cmd1.fdinput);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->cmd2.fdoutput);
}

void	closeCmd(t_cmd *cmd)
{
	close(cmd->fdinput);
	close(cmd->fdoutput);
}

void	closeFiles(t_arg *pipex)
{
	close(pipex->cmd1.fdinput);
	close(pipex->cmd2.fdoutput);
}