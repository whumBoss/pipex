/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:35:21 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/26 17:03:38 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*int	main(void)
{
	const char	*s1 = "on compare a la premiere";
	const char	*s2 = "on compare la deuxieme";
	
	printf("%d\n", strncmp(s1, s2, 14));
	printf("%d\n", ft_strncmp(s1, s2, 14));
	return (0);
}*/