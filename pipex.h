/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:42:46 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/22 17:55:53 by wihumeau         ###   ########.fr       */
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
# include <string.h>
# include <sys/wait.h>
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
	char	**cmd[2];
	char	*path[2];
	char	**envp;
} t_arguments;

//Parsing.c
t_arguments	parsing(char **argv, char **envp);
char		**isoler_path(char **envp);
char		*find_path(char **cmd, char **envp);
char		**file_check(int fd, char *arg, int flag);

//Pipex.c
void		parent(t_arguments pipex);
void		creat_pipe(t_arguments pipex, int p[2]);
int			exec_cmd2(t_arguments pipex, int tab_pid[2], int i);
int			exec_cmd1(t_arguments pipex, int p[2], int tab_pid[2], int i);
void		no_cmd(t_arguments pipex, int p[]);
int			child(t_arguments pipex, int j, int tab_pid[2], int i);

//Pipex_utils.c
void		free_all(t_arguments pipex);
void		free_tab(char **tab);
void		close_files(t_arguments pipex);
void		close_pipe(int p[2]);

#endif