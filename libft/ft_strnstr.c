/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:35:59 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/14 15:41:00 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*little_start;
	char	*bookmark;
	size_t	sublen;

	if (!*little)
		return ((char*)big);
	little_start = (char*)little;
	while (len-- && *big)
	{
		bookmark = (char*)big;
		sublen = len + 1;
		while (*little && sublen-- && *big && *little == *big)
		{
			if (!*(little + 1))
				return (bookmark);
			little++;
			big++;
		}
		big = bookmark;
		little = little_start;
		big++;
	}
	return (NULL);
}
