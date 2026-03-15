/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:26:08 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/27 16:19:55 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	ft_ex(unsigned int i, char c)
{
	int		i;
	int		len;
	char	*nv_s;

	if (i % 2 == 0)
		return ('a');
	return (c);
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*nv_s;

	i = 0;
	len = ft_strlen(s) + 1;
	nv_s = malloc(sizeof(char) * len);
	if (!nv_s)
		return (NULL);
	while (s[i])
	{
		nv_s[i] = f(i, s[i]);
		i++;
	}
	nv_s[i] = '\0';
	return (nv_s);
}
/*int	main(void)
{
	const char	*s = "bbbbbbbbbbbbbbbbbbbbbbb";
	char	*result = ft_strmapi(s, ft_ex);
	printf("%s\n", result);
	return(0);
}*/