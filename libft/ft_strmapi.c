/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 21:00:50 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/04 21:28:04 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*buffer;

	buffer = ft_strdup((char *)s);
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = f(i, buffer[i]);
		i++;
	}
	return (buffer);
}
