/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:00:17 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/25 19:29:49 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*arr;

	if (size != 0 && n >= ~(size_t)0 / size)
		return (NULL);
	arr = malloc(n * size);
	if (!arr)
		return (NULL);
	if (n == 0 || size == 0)
		return (arr);
	ft_bzero(arr, n * size);
	return (arr);
}
