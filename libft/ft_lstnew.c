/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:36:46 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 16:42:54 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	if ((elem = (t_list*)malloc(sizeof(t_list))))
	{
		elem->next = NULL;
		elem->content = content;
	}
	return (elem);
}
