/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:05:50 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/10/15 19:35:59 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	after_dot(double num, char *string, size_t i)
{
	double	divisor;

	divisor = 10.0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		num += (string[i++] - '0') / divisor;
		divisor *= 10.0;
	}
	return (num);
}

double	ft_atof(char *string)
{
	size_t	i;
	double	num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0.0;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == 32)
		i++;
	if (string[i] == '-')
		sign = -1;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		num = num * 10 + (string[i++] - '0');
		if (string[i] == '.')
		{
			num = after_dot(num, string, i + 1);
			break;
		}
	}

	return ((num * sign));
}
