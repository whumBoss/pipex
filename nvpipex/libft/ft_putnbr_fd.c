/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:16:14 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 15:31:10 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * (-1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd('0' + nb % 10, fd);
}
/*int	main(void)
{
	int	fd = open("testnbr.txt", O_WRONLY);
	int	nb = -254;
	ft_putnbr_fd(nb, fd);
	return (0);
}*/