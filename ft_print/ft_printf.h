/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:35:13 by wihumeau          #+#    #+#             */
/*   Updated: 2026/01/02 17:43:45 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_puthexa(long nb, char c);
int	ft_putadrs(void *ptr);
int	ft_convert(unsigned long long adrs);
int	ft_specificator(char *s, va_list list, int i);

# define MAX_VALUE 4294967295

#endif