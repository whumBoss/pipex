/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:46:14 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 15:13:05 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*nv_s1;
	unsigned char	*nv_s2;
	size_t			i;

	i = 0;
	nv_s1 = (unsigned char *)s1;
	nv_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (nv_s1[i] != nv_s2[i])
			return (nv_s1[i] - nv_s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	*s1;
	const char	*s2;
	size_t	n;
	
	s1 = "on compare";
	s2 = "on a";
	n = 2;
	printf("%d\n", memcmp(s1, s2, n));
	printf("%d\n", ft_memcmp(s1, s2, n));
}*/