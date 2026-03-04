/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wissalhumeau <wissalhumeau@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:09:30 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/04 21:57:40 by wissalhumea      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*PARSING : 

	ON TRAITE LA CHAINE DE CARACTERES (argv[1 a 4])
	{
		ON CONSIDERE ARGV[1] = INFILE 
		{
			arguments->fd_infile = open(ARGV1)
			SI MAUVAISE INFILE -> ON QUITTE ET ON SORT 1
			soit l'entree standard
		}
		ON CONSIDERE ARGV[4] = OUTFILE 
		{
			arguments->fd_outfile = open(ARGV[4])
			SI ERREUR POUR OUTFILE -> ON QUITTE ET ON RESSORT 2 
			foit la sortie standard
		}

		ON CONSIDERE ARGV[2] = CMD1
		{
			SI (ARGV[2] CONTIENT LE PATH ENTIER (USR/BIN/LS))
				CMD[1][0] = USR/BIN/LS || PATH = USR/BIN/LS
				CMD[1][i] = CONTENU SPLIT
			SINON
				ON RECUPRE PATH;
				ON SPLIT EN FONCTION DES :
				ON TESTE POUR CHAQUE SPLIT[i]
				SI access(F_OK)
					CMD[1][0] = SPLIT[i] + CMD
		}
		ON CONSIDERE ARGV[3] = CMD2
		{
			SI (ARGV[2] CONTIENT LE PATH ENTIER (USR/BIN/LS))
					CMD[1][0] = USR/BIN/LS || PATH = USR/BIN/LS
					CMD[1][i] = CONTENU SPLIT
			SINON
				ON RECUPRE PATH;
				ON SPLIT EN FONCTION DES :
				ON TESTE POUR CHAQUE SPLIT[i]
				SI access(F_OK)
					CMD[1][0] = SPLIT[i] + CMD
		}
	}*/

char	**checkcmd(char *arg)
{
	char	**cmd;

	if (!arg || !*arg || *arg == ' ' || (arg[0] == '/' && arg[1] == '\0'))
		return (NULL);
	if (access(arg, F_OK | X_OK) == 0)
	{
		cmd = malloc(sizeof(char *)* 2);
		if (!cmd)
			return (NULL);
		cmd[0] = arg;
		cmd[1] = NULL;
		return (cmd);
	}
	cmd = ft_split(arg, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}

int		openoutfile(char *file)
{
	int		fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(file);
		return (2);
	}
	return (fd);
}

int		openinfile(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (1);
	}
	return (fd);
}

void	parscmd(t_arg *pipex, char **av)
{
	pipex->cmd1.fdinput = openinfile(pipex->infile);
	pipex->cmd2.fdoutput = openoutfile(pipex->outfile);
	pipex->cmd1.cmd = checkcmd(av[2]);
	pipex->cmd2.cmd = checkcmd(av[3]);
	pipex->cmd1.path = assignpath(pipex->cmd1.cmd, pipex);
	pipex->cmd2.path = assignpath(pipex->cmd2.cmd, pipex);
}

void	parsing(t_arg *pipex, char **av)
{
	pipex->infile = av[1];
	pipex->outfile = av[4];
	parscmd(pipex, av);
}