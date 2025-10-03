/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:25:59 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/01 20:59:31 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(long n)
{
	long	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	long	num;
	int		len;

	num = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	len = numlen(n);
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	if (num < 0)
	{
		newstr[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		newstr[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (newstr);
}
