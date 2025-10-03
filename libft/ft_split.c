/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:12:27 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/05 22:16:56 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	int		in_world;

	count = 0;
	in_world = 0;
	while (*s)
	{
		if (*s != c && in_world == 0)
		{
			in_world = 1;
			count++;
		}
		if (*s == c)
			in_world = 0;
		s++;
	}
	return (count);
}

static char	**free_all(char **newstr, int j)
{
	while (j--)
		free(newstr[j]);
	free(newstr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**newstr;
	size_t	j;

	i = 0;
	len = 0;
	j = 0;
	newstr = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!newstr)
		return (NULL);
	while (j < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		len = i;
		while (s[len] && s[len] != c)
			len++;
		newstr[j++] = ft_substr(s, i, len - i);
		if (!newstr[j - 1])
			return (free_all(newstr, j - 1));
		i = len;
	}
	return (newstr);
}
