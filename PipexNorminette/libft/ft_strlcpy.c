/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:07:46 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/25 13:26:04 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	len_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (len_src);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_src);
}

/*int main(void)
{
	char dest1[50] = "epowefjpofjewpof";
	char dest2[50] = "epowefjpofjewpof";
	const char *src = "hello";
	size_t size = -1;

	printf("===== LA VRAI =====\n");
	printf("%zu\n", strlcpy(dest1, src, size));
	printf("%s\n", dest1);
	printf("===== LA FAUSSE =====\n");
	printf("%zu\n", ft_strlcpy(dest2, src, size));
	printf("%s\n", dest2);
}*/