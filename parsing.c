/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/13 17:56:18 by wihumeau         ###   ########.fr       */
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
	//SI IL Y A PAS DE CMD, ASSIGNER PATH A NULL
	if (!cmd)
		return (NULL);
	//SINON ASSIGNER LE PATH
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

char	**file_check(int fd, char *arg, int flag)
{
	char	**cmd;
	//TEST SI INFILE INVALIDE: PAS CMD1
	if (fd < 0)
	{
		fd = open("dev/null", flag);
		cmd = NULL;
		ft_printf("Erreur pipex : %s\n", errno);
	}
	//SI INFILE VALIDE: ASSIGNER LA CMD1
	else
	{
		cmd = ft_split(arg);
	}
	//RETURN LA CMD1 POUR L'UTILISER DANS LES CONDITIONS SUIVANTES
	return (cmd);
}

t_arguments	parsing(char **argv, char **envp)
{
	t_arguments	pipex;
	
	pipex.infile = argv[1]; //dup ou pas besoin?
	pipex.outfile = argv[4];//dup ou pas besoin?
	pipex.fd_infile = open(pipex.infile, O_RDONLY);
	pipex.fd_outfile = open(pipex.outfile, O_WRONLY);
	//VERIF LES FD ET ASSIGNER LES CMD
	pipex.cmd1 = file_check(pipex.fd_infile, argv[2], O_RDONLY);
	pipex.cmd2 = file_check(pipex.fd_outfile, argv[3], O_WRONLY);
	//VERIF SI !CMD POUR ASSIGNER OU PAS LES PATH
	pipex.path1 = find_path(pipex.cmd1[0]);
	pipex path2 = find_path(pipex.cmd2[0]);
	pipex.envp = envp;
	
	return (pipex);
}
