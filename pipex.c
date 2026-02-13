/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/13 20:00:25 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char *path, char **cmd, char **envp)
{
	int	pid = fork();
	
	if (pid == 0)
	{
		if (!execve(path, cmd, envp))
		{
			ft_printf("Erreur pipex : %s\n", errno);
		}
		return (1);
	}
	else
	{
		(void)path;
		(void)cmd;
		(void)envp;
	}
	return (0);
	}
	
// char	**file_check(int fd, char **cmd, int flag)
// {
// 	//TEST INFILE VALIDE? SINON PAS CMD1
// 	if (fd < 0)
// 	{
// 		fd = open("dev/null", flag);
// 		cmd = NULL;
// 		ft_printf("Erreur pipex : %s\n", errno);
// 	}
// 	//RETURN LA CMD1 POUR L'UTILISER DANS LES CONDITIONS SUIVANTES
// 	return (cmd);
// }

void	parent(t_arguments pipex)
{
	//TEST INFILE VALIDE, SI INVALIDE CMD1 ASSIGNER A NULL => dans le parsing
	//pipex.cmd1 = file_check(pipex.fd_infile, pipex.cmd1, O_RDONLY);
	
	//REDIRECTION POUR QUE CHILD1 LISE DANS INFILE
	if (pipex.fd_infile > 0)
	{
		dup2(pipex.fd_infile, STDIN_FILENO); // si mon fd est a -1 et que je fais la redirection c'est ok?
		close(pipex.fd_infile);
	}
	
	//TEST OUTFILE VALIDE, SI INVALIDE CMD2 ASSIGNER A NULL => dans le parsing
	//pipex.cmd2 = file_check(pipex.fd_outfile, pipex.cmd2, O_WRONLY);
	
	//CREATION DU PIPE
	int	p[2];
	if (pipe(p) < 0) //pipe() returns 0 on succes and returns -1 on error
	{
		ft_printf("Erreur pipex, creation du pipe : %d\n", errno);
	}
	
	//VERIF SI IL Y A DES CMD A EXECUTER
	if (pipex.cmd1 == NULL && pipex.cmd2 == NULL)
	{
		ft_printf("Erreur pipex : aucune commande a executer\n");
		return ;
	}
	
	//EXECUTION DE LA CMD1 SI LE INFILE EST VALIDE
	if (pipex.cmd1 != NULL)
	{
		//REDIRECTION POUR QUE CHILD1 ECRIVE DANS PIPE[1]
		dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		//EXECUTION CMD1
		child(pipex.path1, pipex.cmd1, pipex.envp);
		//EXECUTION DE LA CMD2 SI LE INFILE ET OUTFILE EST VALIDE
		if (pipex.cmd2 != NULL)
		{
			//REDIRECTION POUR QUE CHILD2 LISE DANS PIPE[0]
			dup2(p[0], STDIN_FILENO);
			close(p[0]);
			//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
			dup2(pipex.fd_outfile, STDOUT_FILENO);
			close(pipex.fd_outfile);
			//EXECUTION CMD2
			child(pipex.path2, pipex.cmd2, pipex.envp);
		}
	}
	//EXECUTION CMD2 SI LE OUTFILE EST VALIDE ET LE INFILE INVALIDE
	else if (pipex.cmd1 == NULL && pipex.cmd2 != NULL)
	{
		//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
		dup2(pipex.fd_outfile, STDOUT_FILENO);
		close(pipex.fd_outfile);
		//EXECUTION CMD2
		child(pipex.path2, pipex.cmd2, pipex.envp);
	}
	//fonction close all pour fermer tout les fd
	//BESOIN DE MALLOC LES STRING DANS LE TABLEAU
	//FONCTION POUR FREE TOUT : IDENTIFIFIER LES CAS D'ERREUR ET APPELLER LES FONCTIONS FREE DANS CES CAS PRECIS
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		t_arguments	pipex;
		
		// pipex.infile = "infile.txt";
		// pipex.outfile = "outfile.txt";
		// pipex.fd_infile = 
		// pipex.fd_outfile = 
		// pipex.cmd1 = {"cat", "-e", NULL};
		// pipex.cmd2 = {"echo", NULL};
		// pipex.path1 = "/usr/bin/cat";
		// pipex path2 = "/usr/bin/echo";
		// pipex.envp = envp;
		pipex = parsing(argv, envp);
		parent(pipex);
	}
	else
		ft_printf("Erreur pipex : trop ou manque d'arguments\n");
	return (0);
}

// CAS LIMITES
// < infileNonexist cat | ls > outfileExist  || Deuxieme commande executer
// < infileExist cat | ls > outfileNonexist  || Le outfile est creer

// STDINFILENO 0
// STDOUTFILENO 1