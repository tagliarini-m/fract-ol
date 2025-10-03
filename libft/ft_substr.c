/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:47:22 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/29 19:05:45 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			newlen;
	unsigned int	size_s;
	char			*strsub;

	size_s = ft_strlen(s);
	if (start > size_s)
		return (ft_calloc(1, 1));
	newlen = size_s - start;
	if (len > newlen)
		len = newlen;
	strsub = ft_calloc(len + 1, sizeof(char));
	if (strsub == NULL)
		return (NULL);
	ft_strlcpy(strsub, s + start, len + 1);
	return (strsub);
}
