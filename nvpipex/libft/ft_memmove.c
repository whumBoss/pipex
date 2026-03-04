/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:47:52 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 16:03:46 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*nv_dest;
	unsigned char		*nv_src;

	if (!dest && !src)
		return (NULL);
	nv_dest = (unsigned char *)dest;
	nv_src = (unsigned char *)src;
	if (dest > src)
	{
		while (n--)
		{
			nv_dest[n] = nv_src[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/*int	main(void)
{
	char src[] = "bonjour";
	char *dest = src + 2;
	printf("%p\n", src);
	printf("%p\n", dest);
	ft_memmove(dest, src, 7);
	printf("%s\n", src);
	printf("%s\n", dest);

	int	i = 0;
	int	tab_src[] = {4, 5, 6, 7};
	int	*tab_dest = tab_src + 2;
	while (i <= 4)
	{
		printf("%d, ", tab_src[i++]);
	}
	printf("\n");
	i = 0;
	while (i <= 4)
	{

		printf("%d, ", tab_dest[i++]);
	}
	printf("\n");
	ft_memmove(tab_dest, tab_src, 16);
	i = 0;
	while (i <= 4)
	{
		printf("%d, ", tab_src[i++]);
	}
	printf("\n");
	i = 0;
	while (i <= 4)
	{
		printf("%d, ", tab_dest[i++]);
	}
	printf("\n");
}*/