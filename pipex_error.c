/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:19:02 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/24 16:03:25 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	erreur_path(t_arguments *pipex)
{
	free_all(&pipex);
	ft_printf("Erreur pipex, echec lors de l'assignation de la variable\n");
	exit(1);
}
