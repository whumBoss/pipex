/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:55 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/13 21:38:16 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPEX_H
# ifndef PIPEX_H

//Les bibliotheques
# include <>

//Mes fonctions
void	pipex(int argc, char **argv, char envp);

// definir ma structure pipex
// elle vas contenir toutes les variable necessaires 
// mon infile, mon outfile, infile fd, mon nb de cmd
typedef struct arguments
{
	char	*infile;
	char	*outfile;
	int		nb_cmd;
	int		infile_fd;
	int		outfile_fd;
} arguments;

// definir une structure commande liste chainee 
// commande et ses flag splitee
// path
// pointer sur la prochaine commande
typedef struct commandes
{
	char				*cmd;
	char				*flags;
	char				*path;
	struct commandes	*next;
} cmd;

#endif