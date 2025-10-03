/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:06:02 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/30 19:03:56 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	len;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr((char *)set, s1[start]))
		start++;
	while (ft_strchr((char *)set, s1[end]))
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
