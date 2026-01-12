/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:43:09 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/12 19:24:02 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pipex(int argc, char **argv, char envp)
{
	if (argc < 5)
		printf("Erreur pipex pas assez d'arguments: %s\n", strerror(errno));
}

int	main(int argc, char **argv, char **envp)
{
	pipex(argc, argv, envp);
}