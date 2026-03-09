/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:50:42 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:54:30 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mesurer_len(long nb)
{
	int	j;

	j = 0;
	if (nb < 0)
	{
		j++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}

static void	ft_isneg(long *nb, char *num)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		num[0] = '-';
	}
}

static void	ft_wrnum(long nb, int i, char *num)
{
	while (nb != 0)
	{
		num[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;
	long	nb;

	if (n == 0)
	{
		num = malloc(2);
		if (!num)
			return (NULL);
		return (num[0] = '0', num[1] = '\0', num);
	}
	nb = n;
	len = ft_mesurer_len(nb);
	num = malloc(sizeof(char) * len + 1);
	if (!num)
		return (NULL);
	ft_isneg(&nb, num);
	ft_wrnum(nb, len - 1, num);
	num[len] = '\0';
	return (num);
}
// int	main(void)
// {
// 	int n = -2147483648;
// 	char *num = ft_itoa(n);
// 	printf("%s\n", num);
// 	return (0);
// }