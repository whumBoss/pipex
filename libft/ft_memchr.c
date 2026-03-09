/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:28:06 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:58:48 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *pointer, int value, size_t num)
{
	unsigned char	*nv_pointer;
	size_t			i;

	i = 0;
	nv_pointer = (unsigned char *)pointer;
	while (i < num)
	{
		if (nv_pointer[i] == (unsigned char)value)
			return (&nv_pointer[i]);
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	char	str[] = "on chercher Une valeur";
	int	value_c = 85;
	size_t	num_c = 15;
	unsigned char	*result_c_vrai = memchr(str, value_c, num_c);
	unsigned char	*result_c_fausse = ft_memchr(str, value_c, num_c);
	printf("===== LA VRAI =====\n");
	printf("%s\n", result_c_vrai);
	printf("===== LA FAUSSE =====\n");
	printf("%s\n", result_c_fausse);

	int	tab[] = {12, 5, 45, 6};
	int	value_i = 6;
	size_t	num_i = 12;
	unsigned char	*result_i_vrai = memchr(tab, value_i, num_i);
	unsigned char	*result_i_fausse = ft_memchr(tab, value_i, num_i);
	printf("===== LA VRAI =====\n");
	printf("%s\n", result_i_vrai);
	printf("===== LA FAUSSE =====\n");
	printf("%s\n", result_i_fausse);
}*/