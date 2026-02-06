/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/05 19:57:05 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

t_arguments	assign_structure_arg(int argc, char **argv, char **envp)
{
	//Verif mes arg
	if (argc < 5)
	{
		printf("Erreur pipex pas assez d'arguments: %s\n", strerror(errno));
		return (NULL);
	}
	
	//creer la structure
	struct t_arguments	arg;
	
	//Tester mon infile
	int	fd;
	
	fd = open(arg.infile, O_RDONLY);
	if (fd < 0)
		

	//Tester mon outfile
	
	//Assigner ma structure pipex
	
	arg.infile = argv[1];
	arg.outfile = argv[argc -1];
	arg.nb_cmd = argc - 3;


}