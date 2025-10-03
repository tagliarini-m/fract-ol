/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:49:46 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/25 20:27:37 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (count--)
			*(d + count) = *(s + count);
	}
	else
	{
		i = 0;
		while (count > i)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dest);
}
