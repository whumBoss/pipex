/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:39:35 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 16:02:46 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// char	*variable_path = ft_strnstr(envp[i], "PATH=/home", len);
// int		ic = index_strchr(variable_path, '/');
//char	*chemins_variable = ft_substr(variable_path, ic, 100);
// for (int i = 0; variable_path[i]; i++){
// 	ft_printf("%s\n", variable_path[i]);
// }
// for (int i = 0; chemins_tableau[i]; i++){
// 	ft_printf("%s\n", chemins_tableau[i]);
// }

char	**isoler_path(char **envp, t_arguments *pipex)
{
	int		i;
	int		len;
	char	**variable_path;
	char	**chemins_tableau;

	i = 0;
	len = 0;
	while (envp[i])
	{
		len = ft_strlen(envp[i]);
		if (ft_strnstr(envp[i], "PATH=/home", len))
		{
			variable_path = ft_split(envp[i], '=');
			if (variable_path == NULL)
				erreur_path(&pipex);
			chemins_tableau = ft_split(variable_path[1], ':');
			if (chemins_tableau == NULL)
				erreur_path(&pipex);
			free_tab(variable_path);
			return (chemins_tableau);
		}
		i++;
	}
	return (NULL);
}

//SI IL Y A PAS DE CMD, ASSIGNER PATH A NULL
//SINON ASSIGNER LE PATH
// {
	// 	ft_printf("okk\n");
// {
// free_tab(chemins_tableau);

char	*find_path(char **cmd, char **envp, t_arguments *pipex)
{
	int		i;
	char	**chemins_tableau;
	char	*cmd_complete;
	char	*cmd_path;

	i = 0;
	chemins_tableau = isoler_path(envp, &pipex);
	if (cmd == NULL)
		return (NULL);
	cmd_complete = ft_strjoin("/", cmd[0]);
	if (cmd_complete == NULL || chemins_tableau == NULL)
		erreur_path();
	while (chemins_tableau[i])
	{
		cmd_path = ft_strjoin(chemins_tableau[i], cmd_complete);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_paths(&cmd_complete, &chemins_tableau)
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

//TEST SI INFILE INVALIDE: PAS CMD1
//SI INFILE VALIDE: ASSIGNER LA CMD1
//RETURN LA CMD1 POUR L'UTILISER DANS LES CONDITIONS SUIVANTES

char	**file_check(int fd, char *arg, int flag, t_arguments *pipex)
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
		{
			cmd = ft_split(arg, ' ');
			if (cmd == NULL)
				erreur_path(&pipex);
		}
	}
	return (cmd);
}

//VERIF LES FD ET ASSIGNER LES CMD
//VERIF SI !CMD POUR ASSIGNER OU PAS LES PATH

int	parsing(t_arguments *pipex, char **argv, char **envp)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[4];
	pipex->fd_infile = open(pipex->infile, O_RDONLY);
	if (pipex->fd_infile < 0)
	{
		pipex->fd_infile = open("/dev/null", O_CREAT);
		printf("Erreur pipex, fd_infile : %s\n", strerror(errno));
	}
	pipex->fd_outfile = open(pipex->outfile,
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_outfile < 0)
		printf("Erreur pipex, fd_outfile: %s\n", strerror(errno));
	pipex->cmd[0] = file_check(pipex->fd_infile, argv[2], O_RDONLY, &pipex);
	pipex->cmd[1] = file_check(pipex->fd_outfile, argv[3], O_WRONLY, &pipex);
	pipex->path[0] = find_path(pipex->cmd[0], envp, &pipex);
	pipex->path[1] = find_path(pipex->cmd[1], envp, &pipex);
	pipex->envp = envp;
	return (0);
}

//valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes 
// ./pipex infile.txt "/bin/ls" "/bin/cat" outfile.txt