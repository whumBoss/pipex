/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:11:05 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/25 17:13:24 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = (char *)str1;
	s2 = (char *)str2;
	if (!*s2)
		return (s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
			if (s2[j] == '\0')
				return (&s1[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main (void)
{
	//char *str = strnstr("wissal est la bosse", "la", 20);
	//printf("%s\n", str);
// 
	// char	*str1 = "logan le prof";
	// char 	*str2 = "";
// 
	// char	*vrai = strnstr(str1, str2, 15);
	// printf("%s\n", vrai);
	// char	*result = ft_strnstr(str1, str2, 15);
	// printf("%s\n", result);
	char *s1 = "MZIRIBMZIRIBMZE123";
 	char *s2 = "MZIRIBMZE";
 	size_t max = strlen(s2);
 	char *i1 = strnstr(s1, s2, max);
 	char *i2 = ft_strnstr(s1, s2, max);
	printf("%s\n", i1);
	printf("%s\n", i2);
}*/