/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:53:44 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/22 17:52:18 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i = 0;

	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// void	free_double_tab(char ***double_tab)
// {
// 	int	j;

// 	j = 0;
// 	while (double_tab[j])
// 	{
// 		free_tab(double_tab[j]);
// 		j++;
// 	}
// 	free(double_tab);
// }

void	free_all(t_arguments pipex)
{
	if (pipex.cmd[0])
		free_tab(pipex.cmd[0]);
	if (pipex.cmd[1])
		free_tab(pipex.cmd[1]);
	if (pipex.path[0])
		free(pipex.path[0]);
	if (pipex.path[1])
		free(pipex.path[1]);
}

void	close_files(t_arguments pipex)
{
	close(pipex.fd_infile);
	close(pipex.fd_outfile);
}

void	close_pipe(int p[2])
{
	close(p[0]);
	close(p[1]);
}