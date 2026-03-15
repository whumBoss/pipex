/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:02:17 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 20:19:24 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_end_index(char const *s1, char const *set, int len)
{
	while (len >= 0 && ft_is_set(set, s1[len]))
		len--;
	return (len);
}

static int	ft_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_set(set, s1[i]))
			i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len_trim;
	int		len_total;
	char	*result;

	start = ft_start_index(s1, set);
	len_total = ft_strlen(s1);
	end = ft_end_index(s1, set, len_total - 1);
	len_trim = end - start;
	result = ft_substr(s1, start, len_trim + 1);
	return (result);
}
// int	main(void)
// {
// 	char const	*s1 = "!!hel!lo!!";
// 	char const	*set = "!";
// 	char	*s2 = ft_strtrim(s1, set);
// 	printf("%s\n", s2);
// 	return (0);
// }