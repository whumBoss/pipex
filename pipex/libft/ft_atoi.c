/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wihumeau <wihumeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:44 by wihumeau          #+#    #+#             */
/*   Updated: 2025/11/24 18:19:45 by wihumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * signe);
}
/*int	main(void)
{
	char	str1[] = "458hbefde";
	char	str2[] = "-458hbefde";
	char	str3[] = "456-458hbefde";
	char	str4[] = "ruyhgvh-458hbefde";
	char	str5[] = "     -458hbefde";
	char	str6[] = ".;;.-458hbefde";
	char	str7[] = "\n-458hbefde";
	
	printf("===== ATOI =====\n");
	printf("%d\n", atoi(str1));
	printf("%d\n", atoi(str2));
	printf("%d\n", atoi(str3));
	printf("%d\n", atoi(str4));
	printf("%d\n", atoi(str5));
	printf("%d\n", atoi(str6));
	printf("%d\n", atoi(str7));
	printf("===== ATOI =====\n");
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", ft_atoi(str4));
	printf("%d\n", ft_atoi(str5));
	printf("%d\n", ft_atoi(str6));
	printf("%d\n", ft_atoi(str7));
	return (0);
}*/