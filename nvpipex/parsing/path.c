/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wissalhumeau <wissalhumeau@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:37:34 by wissalhumea       #+#    #+#             */
/*   Updated: 2026/03/04 21:46:17 by wissalhumea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**isolatepath(t_arg *pipex)
{
	int		i;
	int		len;
	char	**path_variable;
	char	**path_tab;

	i = 0;
	len = 0;
	while (pipex->env[i])
	{
		len = ft_strlen(pipex->env[i]);
		if (ft_strnstr(pipex->env[i], "PATH=/", len)) //"PATH=/home"
		{
			path_variable = ft_split(pipex->env[i], '=');
			// if (path_variable == NULL)
			// 	error_path(pipex);
			path_tab = ft_split(path_variable[1], ':');
			// if (path_tab == NULL)
			// {
			// 	free_tab(path_variable);
			// 	error_path(pipex);
			// }
			//free_tab(path_variable);
			return (path_tab);
		}
		i++;
	}
	return (NULL);
}

char	*findpath(char **cmd, t_arg *pipex)
{
	int		i;
	char	**path_tab;
	char	*complete_cmd;
	char	*cmd_path;

	if (!cmd)
		return (NULL);
	i = 0;
	path_tab = isolatepath(pipex);
	if (!path_tab)
		return (NULL);
	complete_cmd = ft_strjoin("/", cmd[0]);
	// if (complete_cmd == NULL)
	// {
	// 	free_tab(path_tab);
	// 	error_path(pipex);
	// }
	while (path_tab[i])
	{
		cmd_path = ft_strjoin(path_tab[i], complete_cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			//free_paths(&complete_cmd, &path_tab);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	//free_paths(&complete_cmd, &path_tab);
	return (NULL);
}

char	*assignpath(char **cmd, t_arg *pipex)
{
	if (cmd[0] == NULL)
		return (NULL);
	if (access(cmd[0], F_OK | X_OK) == 0)
		return (cmd[0]);
	return(findpath(cmd, pipex));
}