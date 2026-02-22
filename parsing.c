/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/22 18:01:58 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*variable_PATH = ft_strnstr(envp[i], "PATH=/home", len);
// int		ic = index_strchr(variable_PATH, '/');
//char	*chemins_variable = ft_substr(variable_PATH, ic, 100);
char	**isoler_path(char **envp)
{
	int	i = 0;
	int	len = 0;

	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			char	**variable_PATH = ft_split(envp[i], '=');
			for (int i = 0; variable_PATH[i]; i++){
				ft_printf("%s\n", variable_PATH[i]);
			}
			char	**chemins_tableau = ft_split(variable_PATH[1], ':');
			for (int i = 0; chemins_tableau[i]; i++){
				ft_printf("%s\n", chemins_tableau[i]);
			}
			free_tab(variable_PATH);
			exit(1);
			return (chemins_tableau);
		}
		i++;
	}
	return (NULL);
}

//SI IL Y A PAS DE CMD, ASSIGNER PATH A NULL
//SINON ASSIGNER LE PATH
char	*find_path(char **cmd, char **envp)
{
	if (cmd == NULL)
	// {
	// 	ft_printf("okk\n");
		return (NULL);
	// }
	int		i = 0;
	char	**chemins_tableau = isoler_path(envp);
	char	*cmd_complete = ft_strjoin("/", cmd[0]);
	while (chemins_tableau[i])
	{
		char	*cmd_path = ft_strjoin(chemins_tableau[i], cmd_complete);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free(cmd_complete);
			free_tab(chemins_tableau);
			return cmd_path;
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

//TEST SI INFILE INVALIDE: PAS CMD1
//SI INFILE VALIDE: ASSIGNER LA CMD1
//RETURN LA CMD1 POUR L'UTILISER DANS LES CONDITIONS SUIVANTES
char	**file_check(int fd, char *arg, int flag)
{
	char	**cmd;

	cmd = NULL;
	if (fd < 0)
	{
		fd = open("/dev/null", flag);
		cmd = NULL;
	}
	else
	{
		if (arg[0] != '\0')
			cmd = ft_split(arg, ' ');
	}
	return (cmd);
}

//VERIF LES FD ET ASSIGNER LES CMD
//VERIF SI !CMD POUR ASSIGNER OU PAS LES PATH
t_arguments	parsing(char **argv, char **envp)
{
	t_arguments	pipex;
	
	pipex.infile = argv[1];//dup ou pas besoin? pas besoin
	pipex.outfile = argv[4];//dup ou pas besoin? pas besoin
	pipex.fd_infile = open(pipex.infile, O_RDONLY);
	if (pipex.fd_infile < 0)
	{
		pipex.fd_infile = open("/dev/null", O_CREAT);
		printf("Erreur pipex, fd_infile : %s\n", strerror(errno));
	}
	pipex.fd_outfile = open(pipex.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex.fd_outfile < 0)
		printf("Erreur pipex, fd_outfile: %s\n", strerror(errno));
	pipex.cmd[0] = file_check(pipex.fd_infile, argv[2], O_RDONLY);
	pipex.cmd[1] = file_check(pipex.fd_outfile, argv[3], O_WRONLY);
	pipex.path[0] = find_path(pipex.cmd[0], envp);
	pipex.path[1] = find_path(pipex.cmd[1], envp);
	pipex.envp = envp;
	return (pipex);
}
