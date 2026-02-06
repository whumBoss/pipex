/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/06 22:00:40 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1(t_arguments pipex)
{
	int	pid1 = fork()
	
	if (pid1 == 0)
	{
		if (!execve(pipex.path1, cmd1, envp))
		{
			ft_printf("Erreur pipex : %s\n", errno);
		}
		return (1);
	}
	return (0);
}
int	child2(t_arguments pipex)
{
	int	pid2 = fork()
	
	if (pid2 == 0)
	{
		if (!execve(pipex.path2, cmd2, envp))
		{
			ft_printf("Erreur pipex : %s\n", errno);
		}
		return (1);
	}
	return (0);
}
void	parent(t_arguments pipex)
{
	//TEST INFILE VALIDE? SINON PAS CMD1
	int	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
	{
		fd_infile = open("dev/null");
		pipex.cmd1 = NULL;
		ft_printf("Erreur pipex : %s\n", errno);
	}
	
	//TEST OUTFILE VALIDE? SINON PAS CMD2
	int	fd_outfile = open(pipex.outfile, O_WRONLY | O_CREATE | O_TRUNC);
	if (fd_outfile < 0)
	{
		fd_outfile = open(dev/null);
		pipex.cmd2 = NULL;
		ft_printf("Erreur pipex : %s\n", errno);
	}
	
	//REDIRECTION POUR QUE CHILD1 LISE DANS INFILE
	dup2(fd_infile, STDINFILENO);
	close(fd_infile);
	
	//CREATION DU PIPE
	int	p[2];
	pipe(p);
	//verif retour de pipe si c > 0 c'est ok
	
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
		dup2(p[1], STDOUTFILENO);
		close(p[1]);
		//EXECUTION CMD1
		child1(pipex);
		//EXECUTION DE LA CMD2 SI LE INFILE ET OUTFILE EST VALIDE
		if (pipex.cmd2 != NULL)
		{
			//REDIRECTION POUR QUE CHILD2 LISE DANS PIPE[0]
			dup2(p[0], STDINFILENO);
			close(p[0]);
			//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
			dup2(fd_outfile, STDOUTFILENO);
			close(fd_outfile);
			//EXECUTION CMD2
			child2(pipex);
		}
	}
	//EXECUTION CMD2 SI LE OUTFILE EST VALIDE ET LE INFILE INVALIDE
	else if (pipex.cmd1 == NULL && pipex.cmd2 != NULL)
	{
		//REDIRECTION POUR QUE CHILD2 ECRIVE DANS OUTFILE
		dup2(fd_outfile, STDOUTFILENO);
		close(fd_outfile);
		//EXECUTION CMD2
		child2(pipex);
	}
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
int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		t_arguments	pipex;
		
		pipex = parsing(argv, envp);
		parent(pipex);
	}
	else
		printf("Erreur pipex : trop ou manque d'arguments\n");
	return (0);
}
// {
// 	t_commandes		*head = NULL;

// 	parsing_struct_cmd(argc, argv, envp, &head);
// 	print_list (head);
// 	return (0);
//}


// CAS LIMITES
// < infileNonexist cat | ls > outfileExist  || Deuxieme commande executer
// < infileExist cat | ls > outfileNonexist  || Le outfile est creer

// STDINFILENO 0
// STDOUTFILENO 1