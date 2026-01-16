/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/16 22:12:19 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct commandes	parsing(int argc, char **argv, char **envp)
{
	// //Verif mes arg
	// if (argc < 5)
	// 	printf("Erreur pipex pas assez d'arguments: %s\n", strerror(errno));
	
	// //Assigner ma structure pipex
	// struct arguments	arg;
	
	// arg.infile = argv[1];
	// arg.outfile = argv[argc -1];
	// arg.nb_cmd = argc - 3;
	// arg.infile_fd = open(infile, O_RDONLY);
	// arg.outfile_fd = open(outfile, O_WRONLY);
	
	//Je veux creer mes nodes et les assigner dans le bon ordre(a l'aide de push back) 
	struct commandes	list_cmd;
	push_back(&list_cmd, ..);
	return ()
}