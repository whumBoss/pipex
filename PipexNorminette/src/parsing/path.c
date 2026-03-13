/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:37:34 by wissalhumea       #+#    #+#             */
/*   Updated: 2026/03/13 21:56:42 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

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
		if (ft_strnstr(pipex->env[i], "PATH=/home", len))
		{
			path_variable = ft_split(pipex->env[i], '=');
			if (path_variable == NULL)
				return (NULL);
			path_tab = ft_split(path_variable[1], ':');
			free_tab(path_variable);
			if (path_tab == NULL)
				return (NULL);
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
	if (complete_cmd == NULL)
		return (free_tab(path_tab), NULL);
	while (path_tab[i])
	{
		cmd_path = ft_strjoin(path_tab[i], complete_cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (free_paths(complete_cmd, path_tab), cmd_path);
		free(cmd_path);
		i++;
	}
	free_paths(complete_cmd, path_tab);
	return (NULL);
}

char	*assignpath(char **cmd, t_arg *pipex)
{
	char	*path;

	if (!cmd || cmd[0] == NULL)
		return (NULL);
	if (access(cmd[0], F_OK | X_OK) == 0)
	{
		path = ft_strdup(cmd[0]);
		if (!path)
			return (NULL);
		return (path);
	}
	return (findpath(cmd, pipex));
}
