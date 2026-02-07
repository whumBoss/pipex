/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 20:06:36 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/07 16:59:10 by wihumeau         ###   ########.fr       */
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
	t_commandes		*current;
	
	new_node = create_node(cmd, path);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

void	print_list(t_commandes *list_cmd)
{
	while (list_cmd)
	{
		printf("Flags: ");
		for (int i = 0; list_cmd->cmd_flags[i]; i++)
			printf("[%s] ", list_cmd->cmd_flags[i]);
		printf("\n");
		printf("Path: %s\n", list_cmd->path);
		list_cmd = list_cmd->next;
	}
}
//ANCIEN PARSING LIST CHAINEE
void	parsing_struct_cmd(int argc, char **argv, char **envp, t_commandes **head)
{
	//verif si le argv[1] est valable(fd)
	
	//verif si argv[2] c'est le chemin et la cmd ou juste la cmd	
	char			*path = NULL;
	int				i;
	
	i = 1;
	while (i < argc)
	{
		path = find_path(argv[i], envp);
		push_back(head, argv[i], path);
		i++;
	}
}
//ANCIEN MAIN PIPEX.BONUS
// {
// 	t_commandes		*head = NULL;

// 	parsing_struct_cmd(argc, argv, envp, &head);
// 	print_list (head);
// 	return (0);
//}


// // ANCIEN .H DECLARATION DES STRUCT CHAINEES
// // definir une structure commande liste chainee 
// // commande et ses flag splitee
// // path
// // pointer sur la prochaine commande
// typedef struct s_commandes
// {
// 	char				**cmd_flags;
// 	char				*path;
// 	struct s_commandes	*next;
// } t_commandes;

// //NODE.c
// void	print_list(t_commandes *list_cmd);
// void	push_back(t_commandes **head, char *cmd, char *path);
// t_commandes	*create_node(char *cmd, char *path);