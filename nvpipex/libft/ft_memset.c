/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:44:20 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 15:30:29 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*nv_pointer;

	i = 0;
	nv_pointer = (unsigned char *)pointer;
	while (i < count)
	{
		nv_pointer[i] = value;
		i++;
	}
	return (nv_pointer);
}
/*int	main(void)
{
	char	cavant[] = "ring";
	int	cvalue = 'w';
	size_t	ccount = -4;
	printf("===== LA VRAI =====\n");
	char	*cvrai = memset(cavant, cvalue, ccount);
	printf("%s\n", cvrai);
	printf("===== LA FAUSSE =====\n");
	char	*capres = ft_memset(cavant, cvalue, ccount);
	printf("%s\n", capres);

	int	iavant[] = {1, 1, 1, 1};
	int	ivalue = 10;
	size_t	icount = 4;
	printf("===== LA VRAI =====\n");
	int	*ivrai = memset(iavant, ivalue, icount);
	printf("%d\n", ivrai[0]);
	printf("===== LA FAUSSE =====\n");
	int	*iapres = ft_memset(iavant, ivalue, icount);
	printf("%d\n", iapres[0]);
	return (0);
}*/