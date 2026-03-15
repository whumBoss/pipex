/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:53:25 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/02 17:14:07 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	writen;

	writen = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		writen += ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
		writen += ft_putnbr(nb / 10);
	writen += ft_putchar('0' + nb % 10);
	return (writen);
}

// int	main()
// {
// 	int	m = ft_putnbr(10);
// 	printf("\n%d\n", m);
// }
