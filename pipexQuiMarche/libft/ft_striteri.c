/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:43:55 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 20:18:50 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_ex(unsigned int i, char *s)
// {
// 	s[i] = 'a';
// }
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char	s[] = "bbbbbbbbbbbbb";
// 	printf("%s\n", s);
// 	ft_striteri(s, ft_ex);
// 	ft_putstr(s);
// 	return (0);
// }