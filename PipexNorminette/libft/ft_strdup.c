/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:30:55 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:20:22 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(ft_strlen(src) + 1);
	if (!result)
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	const char	src[] = "on copiie!!";
	char	*result_vrai;
	char	*result_fausse;
	//result_vrai = strdup(NULL);
	//printf("%s\n", result_vrai);
	result_fausse = ft_strdup(NULL);
	printf("%s\n", result_fausse);
	//free (result_vrai);
	//free (result_fausse);
	return (0);
}*/