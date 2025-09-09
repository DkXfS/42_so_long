/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:07:47 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:24:54 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t srclen;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	while (--size >= 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (srclen);
}
