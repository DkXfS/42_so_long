/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:19:23 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:19:32 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *temp;

	temp = dest;
	while (*dest != 0)
		dest++;
	while (*src != 0 && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = 0;
	return (temp);
}
