/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:55 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/04 19:00:46 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Les bibliotheques
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

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
typedef struct s_commandes
{
	char				**cmd_flags;
	char				*path;
	struct s_commandes	*next;
} t_commandes;

typedef struct s_arguments
{
	char	*infile;
	char	*outfile;
	int		nb_cmd;
} t_arguments;

//NODE.c
char	**isoler_path(char **envp);
void	print_list(t_commandes *list_cmd);
void	push_back(t_commandes **head, char *cmd, char *path);
char	*find_path(char *cmd, char **envp);
t_commandes	*create_node(char *cmd, char *path);

//Parsing.c
void	parsing_struct_cmd(int argc, char **argv, char **envp, t_commandes **head);






#endif