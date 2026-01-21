/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/21 18:25:22 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_commandes	*parsing_struct_cmd(int argc, char **argv, char **envp)
{
	//verif si le argv[1] est valable(fd)
	
	//verif si argv[2] c'est le chemin et la cmd ou juste la cmd
	
	//Je veux creer mes nodes et les assigner dans le bon ordre(a l'aide de push back) 
	
	t_commandes		*head = NULL;
	char			*path = NULL;
	int				i;
	
	i = 1;
	while (i < argc - 1)
	{
		path = find_path(argv[i], envp);
		push_back(&head, argv[i], path);
		i++;
	}
	return (head);
}

// void	assign_structure_arg(int argc, char **argv, char **envp)
// {
// 	// //Verif mes arg
// 	// if (argc < 5)
	// 	printf("Erreur pipex pas assez d'arguments: %s\n", strerror(errno));
	
	// //Assigner ma structure pipex
	// struct arguments	arg;
	
	// arg.infile = argv[1];
	// arg.outfile = argv[argc -1];
	// arg.nb_cmd = argc - 3;
	// arg.infile_fd = open(infile, O_RDONLY);
	// arg.outfile_fd = open(outfile, O_WRONLY);
	
// }