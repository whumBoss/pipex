/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:06:36 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/16 22:12:16 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

struct commandes	create_node(char *cmd, char *flag, char *path)
{
	struct commandes	new_node = malloc(sizeof(struct commandes));
	
	if (new_node == NULL)
		return (NULL);
	new_node->cmd = ft_strdup(cmd);
	new_node->flag = ft_strdup(flag);
	new_node->path = ft_strdup(path);
	new_node->next = NULL;
	return (new_node);
}

// int		index_strchr(char *str, int c)
// {
// 	int	j;
	
// 	j = 0;
// 	while (str[j])
// 	{
// 		if(str[j] == c)
// 			return (j);
// 		j++;
// 	}
// 	return (0);
// }

char	**isoler_path(char **envp)
{
	int		i = 0;
	int		len = 0;

	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			// char	*variable_PATH = ft_strnstr(envp[i], "PATH=/home", len);
			// int		ic = index_strchr(variable_PATH, '/');
			char	*variable_PATH = ft_split(envp[i], '=');
			char	*chemins_variable = ft_substr(variable_PATH, ic, 100);
			char	**chemins_tableau = ft_split(chemins_variable, ':');
			return (chemins_tableau);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i = 0;
	char	**chemins_tableau = isoler_path(envp);
	char	*cmd_complete = ft_strjoin("/", cmd);
	
	while (chemins_tableau[i])
	{
		char	*cmd_path = ft_strjoin(chemins_tableau[i], cmd_complete);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return cmd_path;
		free(cmd_path);
		i++;
	}
	return (NULL);
}

struct commandes	push_back(struct commande **head, ..)
{
	
}