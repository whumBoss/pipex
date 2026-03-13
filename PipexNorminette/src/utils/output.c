/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 21:02:05 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/13 21:50:44 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_matrix_print(char **matrix, char *type)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("[%s[%d] = %s]\n", type, i, matrix[i]);
		i++;
	}
}

// IMPRIME CONTENU CMD
void	ft_cmd_print(t_cmd *cmd, int nb)
{
	ft_printf("[CMD %d]\n", nb);
	ft_printf("[PATH = %s]\n", cmd->path);
	if (cmd->args)
		ft_matrix_print(cmd->args, "ARG");
	else
		ft_printf("[NO ARGS IN CMD]\n");
	ft_printf("[INFD = %d]\n", cmd->fdinput);
	ft_printf("[OUTFD = %d]\n\n", cmd->fdoutput);
}

// IMPRIME CONTENU STRUCTURE GLOBALE PRINT_ENV = 1 POUR PRINT ENV
void	ft_arg_print(t_arg *arg, int print_env)
{
	ft_printf("[INFILE = %s]\n", arg->infile);
	ft_printf("[OUTFILE = %s]\n", arg->outfile);
	ft_printf("[PIPE[0] = %d]\n", arg->pipe[0]);
	ft_printf("[PIPE[1] = %d]\n", arg->pipe[1]);
	if (print_env != 0)
		ft_matrix_print(arg->env, "ENV");
	ft_printf("\n\n");
}
