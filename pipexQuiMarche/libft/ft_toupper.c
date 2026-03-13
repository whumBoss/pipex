/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:31:15 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 16:09:52 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int main(void)
{
	char	c1 = 'r';
	char	c2 = 'F';
	char	c3 = '!';

	printf("%c\n", ft_toupper(c1));
	printf("%c\n", ft_toupper(c2));
	printf("%c\n", ft_toupper(c3));
	return (0);
}*/