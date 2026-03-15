/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:32:46 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/25 14:23:50 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == 0)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	s[] = "on cherche Y, le deuxieme Y";
	int	chr = 108;

	printf("%p\n", strrchr(s, chr));
	printf("%p\n", ft_strrchr(s, chr));
	printf("%s\n", strrchr(s, chr));
	printf("%s\n", ft_strrchr(s, chr));
	return (0);
}*/