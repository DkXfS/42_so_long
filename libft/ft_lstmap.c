/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:08:14 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/17 10:12:55 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *start;
	t_list *elem;

	if (!lst)
		return (NULL);
	else
	{
		start = ft_lstnew(f(lst->content));
		if (!start)
			return (NULL);
		elem = start;
		lst = lst->next;
	}
	while (lst)
	{
		elem->next = ft_lstnew(f(lst->content));
		elem = elem->next;
		if (!elem)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (start);
}
