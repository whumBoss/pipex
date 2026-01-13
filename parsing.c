/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/13 21:51:29 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	parsing(int argc, char **argv, char **envp)
{
	//Verif mes arg
	if (argc < 5)
		printf("Erreur pipex pas assez d'arguments: %s\n", strerror(errno));
	
	//Assigner ma structure pipex
	struct arguments	arg;
	
	arg.infile = argv[1];
	arg.outfile = argv[argc -1];
	arg.nb_cmd = argc - 3;
	arg.infile_fd = open(infile, O_RDONLY);
	arg.outfile_fd = open(outfile, O_WRONLY);
	
	//Appel fonction creer mes nodes dans le bon ordre depuis argv[2] jusqua argv[i-1]
	
	
	//Assigner chaque node dans le bon ordre

	
	
}