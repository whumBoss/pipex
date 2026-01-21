/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:06:36 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/21 18:30:10 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commandes	*create_node(char *cmd, char *path)
{
	t_commandes	*new_node = malloc(sizeof(t_commandes));
	
	if (new_node == NULL)
		return (NULL);
	new_node->cmd_flags = ft_split(cmd, ' ');
	new_node->path = path;
	new_node->next = NULL;
	return (new_node);
}

void	push_back(t_commandes **head, char *cmd, char *path)
{
	t_commandes		*new_node;
	t_commandes		*buffer_current;
	
	new_node = create_node(cmd, path);
	printf("DEBUG: head = %p, *head = %p\n", head, *head);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	buffer_current = *head;
	while (buffer_current->next != NULL)
		buffer_current = buffer_current->next;
	buffer_current->next = new_node;
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
	int	i = 0;
	int	len = 0;

	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			// char	*variable_PATH = ft_strnstr(envp[i], "PATH=/home", len);
			// int		ic = index_strchr(variable_PATH, '/');
			char	**variable_PATH = ft_split(envp[i], '=');
			//char	*chemins_variable = ft_substr(variable_PATH, ic, 100);
			char	**chemins_tableau = ft_split(variable_PATH[1], ':');
			free(variable_PATH);
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
	char	**cmd_and_flags = ft_split(cmd, ' ');
	char	*cmd_complete = ft_strjoin("/", cmd_and_flags[0]);
	
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