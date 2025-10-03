/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:10:18 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/07/23 22:16:23 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (c == 0)
		return (&str[strlen]);
	while (strlen >= 0)
	{
		if (str[strlen] == (char)c)
			return (&str[strlen]);
		strlen--;
	}
	return (NULL);
}
