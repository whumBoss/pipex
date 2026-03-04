/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:43:15 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/02 17:42:06 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(long nb, char c)
{
	int		writen;
	char	*base;

	writen = 0;
	if (c >= 'a' && c <= 'z')
		base = "0123456789abcdef";
	if (c >= 'A' && c <= 'Z')
		base = "0123456789ABCDEF";
	if (nb < 0)
	{
		nb *= -1;
		nb = (MAX_VALUE - (nb - 1));
	}
	if (nb >= 16)
		writen += ft_puthexa(nb / 16, c);
	writen += ft_putchar(base[nb % 16]);
	return (writen);
}

// int	main()
// {
// 	int	writen = ft_puthexa(426432, 'f');
// 	printf("\n%d", writen);
// }