/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:58:27 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 16:44:04 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char*)dest;
	temp2 = (unsigned char*)src;
	while (n)
	{
		*temp = *temp2;
		n--;
		temp++;
		if (*temp2 == (unsigned char)c)
			return ((void*)temp);
		temp2++;
	}
	return (NULL);
}
