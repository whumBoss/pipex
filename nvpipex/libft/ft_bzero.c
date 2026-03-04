/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:42:07 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:35:36 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*nv_str;
	size_t			i;

	i = 0;
	nv_str = (unsigned char *)str;
	while (i < n)
	{
		nv_str[i] = 0;
		i++;
	}
}

/*int main ()
{
	char test_diy[] = "CECI EST UN TEST\0 A COPIER AUSSI";
	char test_bin[] = "CECI EST UN TEST\0 A COPIER AUSSI";
	int i = 0;

	void *buf1 = malloc(sizeof(char) * 50);
	if (!buf1)
		return (1);
	unsigned char *dest1 = (unsigned char *)buf1;
	printf("%p && %p\n", buf1, dest1);
	while (i < 50)
	{
		printf("%c", dest1[i]);
		i++;
	}
	void *buf2 = malloc(sizeof(char) * 50);
	ft_memcpy(buf1, test_diy, 50);
	memcpy(buf2, test_bin, 50);
	// while (i < 50)
	// {
	// 	printf("%c",(char)buf1[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// while (i < 50)
	// {
	// 	printf("%c", (char)buf2[i]);
	// 	i++;
	// }
}*/