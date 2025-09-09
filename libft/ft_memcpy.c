/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:01:55 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 16:28:57 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *temp;
	unsigned char *temp2;

	if (!dest && !src)
		return (NULL);
	temp = (unsigned char*)dest;
	temp2 = (unsigned char*)src;
	while (n)
	{
		*temp = *temp2;
		n--;
		temp++;
		temp2++;
	}
	return (dest);
}
