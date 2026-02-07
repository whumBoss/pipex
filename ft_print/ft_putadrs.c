/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:46:26 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/01 20:24:36 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadrs(void *ptr)
{
	unsigned long long	adrs;
	int					writen;

	if (!ptr)
		return (ft_putstr("(nil)"));
	adrs = (unsigned long long)ptr;
	writen = ft_putstr("0x");
	writen += ft_convert(adrs);
	return (writen);
}

int	ft_convert(unsigned long long adrs)
{
	static int	writen;
	char		*base;

	writen = 0;
	base = "0123456789abcdef";
	if (adrs >= 16)
		ft_convert(adrs / 16);
	writen += ft_putchar(base[adrs % 16]);
	return (writen);
}
