/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:02:54 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 13:02:56 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	else
	{
		i = n;
		while (i--)
			((char*)dest)[i] = ((char*)src)[i];
	}
	return (dest);
}
