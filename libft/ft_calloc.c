/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:36:24 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:18:12 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nmemb * size);
	return (result);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	char	*str;

// 	str = malloc(nmemb * size);
// 	if (!str)
// 		return (0);
// 	while(i < nmemb * size)
// 	{
// 		str[i] = '0';
// 		i++;
// 	}
// 	return ((void *)str);
// }
/*
int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = ft_calloc(5, 1);
	s2 = calloc(5, 1);
	ft_putstr_fd("la fausse : ", 1);
	ft_putstr_fd(s1, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("la vrai : ", 1);
	ft_putstr_fd(s2, 1);
}*/