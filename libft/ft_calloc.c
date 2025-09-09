/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:50:26 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 12:50:41 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *alloc_mem;

	alloc_mem = malloc(nmemb * size);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, nmemb * size);
	return (alloc_mem);
}
