/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:16:06 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/24 21:49:06 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	int				i;
	unsigned char	*buffer;

	buffer = (unsigned char *)buf;
	i = 0;
	while (count--)
	{
		if (buffer[i] == (unsigned char)c)
			return (buffer + i);
		i++;
	}
	return (NULL);
}
