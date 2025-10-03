/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:01:31 by mgomes-t          #+#    #+#             */
/*   Updated: 2025/08/05 22:23:59 by mgomes-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_aux;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp_aux = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_aux;
	}
	*lst = NULL;
}
