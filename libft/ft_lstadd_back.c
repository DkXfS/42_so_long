/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:05:18 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/17 09:31:28 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *elem;

	elem = *lst;
	while (elem && elem->next)
		elem = elem->next;
	if (elem)
		elem->next = new;
	else
		*lst = new;
}
