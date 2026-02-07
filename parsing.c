/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/07 14:51:47 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**isoler_path(char **envp)
{
	int	i = 0;
	int	len = 0;

	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			// char	*variable_PATH = ft_strnstr(envp[i], "PATH=/home", len);
			// int		ic = index_strchr(variable_PATH, '/');
			char	**variable_PATH = ft_split(envp[i], '=');
			//char	*chemins_variable = ft_substr(variable_PATH, ic, 100);
			char	**chemins_tableau = ft_split(variable_PATH[1], ':');
			free(variable_PATH);
			return (chemins_tableau);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i = 0;
	char	**chemins_tableau = isoler_path(envp);
	char	**cmd_and_flags = ft_split(cmd, ' ');
	char	*cmd_complete = ft_strjoin("/", cmd_and_flags[0]);
	
	while (chemins_tableau[i])
	{
		char	*cmd_path = ft_strjoin(chemins_tableau[i], cmd_complete);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return cmd_path;
		free(cmd_path);
		i++;
	}
	return (NULL);
}

t_arguments	parsing(char **argv, char **envp)
{
	t_arguments	pipex;
	
	pipex.infile = argv[1];
	pipex.outfile = argv[4];
	pipex.cmd1 = ft_split(argv[2]);
	pipex.cmd2 = ft_split(argv[3]);
	pipex.path1 = find_path(pipex.cmd1[0]);
	pipex path2 = find_path(pipex.cmd2[0]);
	pipex.envp = envp;
	
	return (pipex);
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