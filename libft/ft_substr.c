/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:39:40 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 19:10:57 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	j;
	char	*result;

	j = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[(start) + j] && j < len)
	{
		result[j] = s[(start) + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
// int	main(void)
// {
// 	char const	*s = "copier une partie de la string";
// 	unsigned int	start = 2;
// 	size_t	len = 100;
// 	char	*result = ft_substr(s, start, len);
// 	printf("%s\n", result);
// 	return (0);
// }