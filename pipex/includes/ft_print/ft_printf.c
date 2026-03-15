/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:41:13 by wihumeau          #+#    #+#             */
/*   Updated: 2026/03/13 20:54:09 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		writen;
	char	*s;

	va_start(list, str);
	i = 0;
	writen = 0;
	if (!str)
		return (-1);
	s = (char *)str;
	while (s[i])
	{
		if (s[i] != '%')
			writen += ft_putchar(s[i++]);
		else
		{
			i++;
			writen += ft_specificator(s, &list, i);
			i++;
		}
	}
	va_end(list);
	return (writen);
}

int	ft_specificator(char *s, va_list *list, int i)
{
	int	writen;

	writen = 0;
	if (s[i] == 'd' || s[i] == 'i')
		writen += ft_putnbr(va_arg(*list, int));
	else if (s[i] == 'u')
		writen += ft_putunbr(va_arg(*list, unsigned int));
	else if (s[i] == 'c')
		writen += ft_putchar(va_arg(*list, int));
	else if (s[i] == 's')
		writen += ft_putstr(va_arg(*list, char *));
	else if (s[i] == 'p')
		writen += ft_putadrs(va_arg(*list, void *));
	else if (s[i] == 'x' || s[i] == 'X')
		writen += ft_puthexa(va_arg(*list, int), s[i]);
	else if (s[i] == '%')
		writen += ft_putchar(s[i]);
	return (writen);
}

// #include<stdio.h>
// int	main()
// {
// 	int		n = 0;
// 	int		m = 0;
// 	n = printf("%x\n", -10);
// 	m = ft_printf("%x\n", -10);
// 	printf("%d\n%d\n", n, m);

// 	n = printf("%x\n", -1);
// 	m = ft_printf("%x\n", -1);
// 	printf("%d\n%d\n", n, m);
// 	int		i = 14;
// 	unsigned int	u = 78;
// 	char	*st = NULL;
// 	char	c = '!';
// 	n = printf("i %% am %s %c adresse:%p\n", st, c, &st);
// 	m = ft_printf("i %% am %s %c adresse:%p\n", st, c, &st);
// 	printf("%d\n", n);
// 	printf("%d\n\n", m);

// 	n = printf("hexadecimal: %x et %X\n", 1245, 1245);
// 	m = ft_printf("hexadecimal: %x et %X\n", 1245, 1245);
// 	printf("%d\n", n);
// 	printf("%d\n\n", m);

// 	n = printf("i: %i\nd: %d \nu: %u \n\n", i, -8, u);
// 	m = ft_printf("i: %i\nd: %d \nu: %u \n\n", i, -8, u);
// 	printf("%d\n", n);
// 	printf("%d\n\n", m);
// }