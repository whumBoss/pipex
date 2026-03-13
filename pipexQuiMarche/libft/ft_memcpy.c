/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:02:39 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 17:32:51 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Dest = zone memoire de destination
// Src = zone memoire de source
// n = nombre de bytes que tu veux copier

// 40 = 	40 char
// 			10 ints;
//			5 ptrs;

// n = 40;
// while (src[i])
// "200, 10, 5, 0, -19"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*nv_src;
	unsigned char		*nv_dest;
	size_t				i;

	i = 0;
	nv_dest = (unsigned char *)dest;
	nv_src = (const unsigned char *)src;
	if (nv_src == nv_dest || n == 0)
		return (nv_dest);
	while (i < n)
	{
		nv_dest[i] = nv_src[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
	// char 	src[] = "  il faut que ca marche!! ";
	// char 	buff1[26];
	// char	buff2[26];
	// 
	// memcpy(buff1, src, 26);
	// ft_memcpy(buff2, src, 26);
	// printf("%s\n", buff1);
	// printf("%s\n", buff2);
// }