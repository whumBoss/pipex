/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:42:46 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/12 20:42:50 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Les bibliotheques
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_print/ft_printf.h"

// definir ma structure pipex
// elle vas contenir toutes les variable necessaires 
// mon infile, mon outfile...
typedef struct s_arguments
{
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**envp;
} t_arguments;

//Parsing.c
void	parsing_struct_cmd(int argc, char **argv, char **envp, t_commandes **head);
t_arguments	parsing(char **argv, char **envp);
char	**isoler_path(char **envp);
char	*find_path(char *cmd, char **envp);

//Pipex.c
void	parent(t_arguments pipex);
int	child(char *path, char **cmd, char **envp);
char	**file_check(char *file, char **cmd);

#endif