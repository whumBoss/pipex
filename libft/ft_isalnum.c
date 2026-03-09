/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:30:12 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 15:42:54 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) == 1 || ft_isdigit(c) == 1);
}
/*
int main(void)
{
	char c = ' ';

	printf("%d", ft_isalnum(c));
	return (0);
}*/
