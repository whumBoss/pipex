/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:19:02 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 21:00:01 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_path(t_arguments *pipex)
{
	free_all(pipex);
	ft_printf("Pipex error, variable asignation gone wrong\n");
	free(pipex);
	exit(1);
}
//free, close et terminer le programme car pas de cmd
void	no_cmd(t_arguments *pipex)
{
	ft_printf("Pipex error : no command\n");
	free_all(pipex);
	close_files(pipex);
	free(pipex);
	exit(126);
}
