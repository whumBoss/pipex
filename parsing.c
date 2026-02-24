/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 20:02:06 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*path_variable = ft_strnstr(envp[i], "PATH=/home", len);
// int		ic = index_strchr(path_variable, '/');
// char	*chemins_variable = ft_substr(path_variable, ic, 100);
// for (int i = 0; path_variable[i]; i++){
// 	ft_printf("%s\n", path_variable[i]);
// }
// for (int i = 0; path_tab[i]; i++){
// 	ft_printf("%s\n", path_tab[i]);
// }

char	**isolate_path(char **envp, t_arguments *pipex)
{
	int		i;
	int		len;
	char	**path_variable;
	char	**path_tab;

	i = 0;
	len = 0;
	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			path_variable = ft_split(envp[i], '=');
			if (path_variable == NULL)
				error_path(pipex);
			path_tab = ft_split(path_variable[1], ':');
			if (path_tab == NULL)
			{
				free_tab(path_variable);
				error_path(pipex);
			}
			free_tab(path_variable);
			return (path_tab);
		}
		i++;
	}
	return (NULL);
}

// SI IL Y A PAS DE CMD, ASSIGNER PATH A NULL
// SINON ASSIGNER LE PATH
// {
// 	ft_printf("okk\n");
// {
// free_tab(path_tab);

char	*find_path(char **cmd, char **envp, t_arguments *pipex)
{
	int		i;
	char	**path_tab;
	char	*complete_cmd;
	char	*cmd_path;

	if (!cmd)
		return (NULL);
	i = 0;
	path_tab = isolate_path(envp, pipex);
	if (!path_tab)
		return (NULL);
	complete_cmd = ft_strjoin("/", cmd[0]);
	if (complete_cmd == NULL)
	{
		free_tab(path_tab);
		error_path(pipex);
	}
	while (path_tab[i])
	{
		cmd_path = ft_strjoin(path_tab[i], complete_cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_paths(&complete_cmd, &path_tab);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_paths(&complete_cmd, &path_tab);
	return (NULL);
}

// TEST SI INFILE INVALIDE: PAS CMD1
// SI INFILE VALIDE: ASSIGNER LA CMD1
// RETURN LA CMD1 POUR L'UTILISER DANS LES CONDITIONS SUIVANTES

char	**file_check(int fd, char *arg, int flag, t_arguments *pipex)
{
	char	**cmd;

	cmd = NULL;
	(void)fd;
	(void)flag;
	(void)pipex;
	// if (fd < 0)
	// {
	// 	fd = open("/dev/null", flag); //O_CREAT
	// 	close(fd);
	// 	cmd = NULL;
	// }
	if (fd < 0)
		return (cmd);
	if (!arg || !*arg || *arg == ' ' || *arg == '/')
		return (cmd);
	cmd = ft_split(arg, ' ');
	if (!cmd)
		return (NULL);
	// if (cmd == NULL)
	// 	error_path(pipex);
	return (cmd);
}

// VERIF LES FD ET ASSIGNER LES CMD
// VERIF SI !CMD POUR ASSIGNER OU PAS LES PATH

int	parsing(t_arguments *pipex, char **argv, char **envp)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->fd_infile = open(pipex->infile, O_RDONLY);
	if (pipex->fd_infile < 0)
		ft_printf("Pipex error, fd_infile : %s\n", strerror(errno));
	pipex->fd_outfile = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC,
			0777);
	if (pipex->fd_outfile < 0)
		ft_printf("Erreur pipex, fd_outfile: %s\n", strerror(errno));
	pipex->cmd[0] = file_check(pipex->fd_infile, argv[2], O_RDONLY, pipex);
	pipex->cmd[1] = file_check(pipex->fd_outfile, argv[3], O_WRONLY, pipex);
	pipex->path[0] = find_path(pipex->cmd[0], envp, pipex);
	pipex->path[1] = find_path(pipex->cmd[1], envp, pipex);
	pipex->envp = envp;
	return (0);
}

int	parsing_null(t_arguments *pipex)
{
	pipex->infile = NULL;
	pipex->outfile = NULL;
	pipex->infile_flag = 0;
	pipex->outfile_flag = 0;
	pipex->fd_infile = 0;
	pipex->fd_outfile = 0;
	pipex->cmd[0] = NULL;
	pipex->cmd[1] = NULL;
	pipex->path[0] = NULL;
	pipex->path[1] = NULL;
	pipex->envp = NULL;
	return (0);
}

// valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes
// ./pipex infile.txt "/bin/ls" "/bin/cat" outfile.txt