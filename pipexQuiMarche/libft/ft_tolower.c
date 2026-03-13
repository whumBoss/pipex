/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:48:49 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 16:10:05 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*int main(void)
{
	char	c1 = 'r';
	char	c2 = 'F';
	char	c3 = '!';

	printf("%c\n", ft_tolower(c1));
	printf("%c\n", ft_tolower(c2));
	printf("%c\n", ft_tolower(c3));
	return (0);
}*/