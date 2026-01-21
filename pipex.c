/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/21 18:27:58 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_list(t_commandes *list_cmd)
{
	int	i = 0;
	while (list_cmd && i != 1)
	{
		printf("Flags: ");
		for (int i = 0; list_cmd->cmd_flags[i]; i++)
			printf("[%s] ", list_cmd->cmd_flags[i]);
		printf("\n");
		printf("Path: %s\n", list_cmd->path);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_commandes		*head = NULL;

	head = parsing_struct_cmd(argc, argv, envp);
	print_list (head);
	return (0);
}