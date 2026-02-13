/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:42:46 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/13 18:18:02 by wihumeau         ###   ########.fr       */
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
	int		inflie_flag;
	int		outfile_flag;
	int		fd_infile;
	int		fd_outfile;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	char	**envp;
} t_arguments;

//Parsing.c
t_arguments	parsing(char **argv, char **envp);
char	**isoler_path(char **envp);
char	*find_path(char *cmd, char **envp);
char	**file_check(int fd, char *arg, int flag);

//Pipex.c
void	parent(t_arguments pipex);
int	child(char *path, char **cmd, char **envp);

#endif