/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:10:31 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 18:27:15 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//fonction close all pour fermer tout les fd
// ---> pas vraiment necessaire dans mon cas
//FONCTION POUR FREE TOUT :
// ---> reste des leak, flags valgrind????
// WAIT!!!! 
// --> bug: exit code tjrs 0 meme si les cmd ne sont pas valable

int	main(int argc, char **argv, char **envp)
{
	t_arguments	*pipex;

	if (argc == 5)
	{
		pipex = malloc(sizeof(t_arguments));
		if (!pipex)
			return (1);
		parsing_null(pipex);
		parsing(pipex, argv, envp);
		parent(pipex);
	}
	else if (argc > 5)
		ft_printf("Pipex error : too many arguments, expected 5.\n");
	else if (argc < 5)
		ft_printf("Pipex error : not enough arguments, expected 5.\n");
	return (0);
}

// CAS LIMITES
// < infileNonexist cat | ls > outfileExist  || Deuxieme commande executer
// < infileExist cat | ls > outfileNonexist  || Le outfile est creer

// STDINFILENO 0
// STDOUTFILENO 1