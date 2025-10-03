/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:19:59 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/25 20:37:53 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t count)
{
	size_t	i;
	size_t	j;
	int		lil_len;

	lil_len = ft_strlen(little);
	i = 0;
	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (i + lil_len <= count && big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
