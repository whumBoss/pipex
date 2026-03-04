/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wissalhumeau <wissalhumeau@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:42:46 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/04 21:42:55 by wissalhumea      ###   ########.fr       */
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

typedef struct s_command
{
	char	**cmd;
	char	*path;
	char	fdinput;
	char	fdoutput;
}	t_cmd;

typedef struct s_arguments
{
	char	*infile;
	char	*outfile;
	int		pipe[2];
	char	**env;
	t_cmd	cmd1;
	t_cmd	cmd2;
}	t_arg;

//Main.c
void	init(t_arg *pipex, char **env);

//Parsing.c
int		openinfile(char *file);
int		openoutfile(char *file);
char	**checkcmd(char *arg);
void	parscmd(t_arg *pipex, char **av);
void	parsing(t_arg *pipex, char **av);

//Path.c
char	**isolatepath(t_arg *pipex);
char	*findpath(char **cmd, t_arg *pipex);
char	*assignpath(char **cmd, t_arg *pipex);

//Exec.c

//Free.c
void	free_tab(char **tab);
#endif