/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:18:09 by mafourni          #+#    #+#             */
/*   Updated: 2024/02/23 13:47:14 by mafourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	result;
	int	comptesign;

	result = 0;
	comptesign = 1;
	if (!str)
		return (0);
	while ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			comptesign = -1;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9')
	{
		result = result * 10 + (str[0] - '0');
		str ++;
	}
	return (result * comptesign);
}
