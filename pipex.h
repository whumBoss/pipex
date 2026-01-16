/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:55 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/16 21:59:07 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PIPEX_H
# ifndef PIPEX_H

//Les bibliotheques
#include <stdio.h>
#include <unistd.h>
# include "libft/libft.h"

//Mes fonctions
struct commandes	parsing(int argc, char **argv, char **envp);
struct commandes	create_node(char *cmd, char *flag, char *path);
char	**isoler_path(char **envp);
char	*find_path(char *cmd, char **envp);
int		index_strchr(char *str, int c);
void	pipex(int argc, char **argv, char envp);

// definir ma structure pipex
// elle vas contenir toutes les variable necessaires 
// mon infile, mon outfile, infile fd, mon nb de cmd
// typedef struct arguments
// {
// 	char	*infile;
// 	char	*outfile;
// 	int		nb_cmd;
// 	int		infile_fd;
// 	int		outfile_fd;
// } arguments;

// definir une structure commande liste chainee 
// commande et ses flag splitee
// path
// pointer sur la prochaine commande
typedef struct commandes
{
	char				**cmd_flags;
	char				*path;
	struct commandes	*next;
} commandes;

#endif