/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:42:46 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/13 21:47:12 by wihumeau         ###   ########.fr       */
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

// RENAME CMD EN ARG POUR SUIVRE LA LOGIQUE DE EXECVE
// char	**cmd;
// FDIN ET OUT SONT DES INTS PAS DES CHARS
// char	fdinput;
// char	fdoutput;
typedef struct s_command
{
	char	**args;
	char	*path;
	int		fdinput;
	int		fdoutput;
}	t_cmd;

// A MODIFIER -> s_arguments / t_arg = s_data / t_data ou s_pipex / t_pipex
typedef struct s_arguments
{
	int		tab_pid[2];
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
void	exec(t_arg *pipex);
int		child(t_arg *pipex, t_cmd *cmd);

//Free.c
void	free_tab(char **tab);
void	free_paths(char *complete_cmd, char **path_tab);
void	free_pipex(t_arg *pipex);
void	free_cmd(t_cmd *cmd);

//Close.c
void	close_files(t_arg *pipex);
void	close_pipex(t_arg *pipex);
void	close_cmd(t_cmd *cmd);

// OUTPUT.C
void	ft_matrix_print(char **matrix, char *type);
void	ft_cmd_print(t_cmd *cmd, int nb);
void	ft_arg_print(t_arg *arg, int print_env);
#endif