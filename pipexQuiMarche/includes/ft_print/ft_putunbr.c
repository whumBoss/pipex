/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:54:57 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/01 20:24:55 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	static int	writen;

	writen = 0;
	if (nb > 9)
		ft_putunbr(nb / 10);
	writen += ft_putchar('0' + nb % 10);
	return (writen);
}
