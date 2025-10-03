/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:45:14 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/24 21:01:16 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	srcsize;
	size_t	to_copy;

	destsize = ft_strlen(dest);
	srcsize = ft_strlen(src);
	if (size == 0)
		return (srcsize);
	if (!src)
		return (destsize);
	if (destsize >= size)
		return (size + srcsize);
	to_copy = size - destsize - 1;
	if (to_copy > srcsize)
		to_copy = srcsize;
	ft_memcpy(dest + destsize, src, to_copy);
	dest[destsize + to_copy] = '\0';
	return (destsize + srcsize);
}
