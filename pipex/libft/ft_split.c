/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:34:31 by wihumeau          #+#    #+#             */
/*   Updated: 2026/02/23 16:39:27 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_assign_s(char const *s, char c, int i)
{
	int		j;
	int		len;
	char	*str;

	j = 0;
	len = 0;
	while (s[i + len] && s[i + len] != c)
	{
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_assign_tab(char const *s, char c, char **tab, int nb_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < nb_str)
	{
		while (s[i] && s[i] == c)
			i++;
		tab[j] = ft_assign_s(s, c, i);
		if (!tab[j])
		{
			ft_free_tab(tab, j + 1);
			return (NULL);
		}
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

static int	ft_nb_str(char const *s, char c)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	if (!*s)
		return (0);
	if (s[0] != c)
		nb = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (i > 0 && s[i - 1] && (s[i - 1] == c))
				nb++;
			i++;
		}
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	int		nb_str;
	char	**tab;

	nb_str = ft_nb_str(s, c);
	tab = malloc(sizeof(char *) * (nb_str + 1));
	if (!tab)
		return (NULL);
	tab = ft_assign_tab(s, c, tab, nb_str);
	return (tab);
}
/*
int	main(void)
{
	int	i;

	char	**splitee = ft_split("Hello!", ' ');
	i = 0;
	while (splitee[i])
	{
		printf("%s\n", splitee[i]);
		i++;
	}
	ft_free_tab(splitee, i);
	return (0);
}*/