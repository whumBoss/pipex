/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:14:40 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/25 12:59:17 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (siz <= len_dst)
		return (siz + len_src);
	while (src[i] && ((len_dst + i) < (siz - 1)))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
/*
int	main(void)
{
	char	dst[20] = "hello";
	const char	src[] = "world";
	size_t	size = 20;

	ft_strlcat(dst, src, size);
	printf("%s\n", dst);
	return (0);
}*/