/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:19:01 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 14:19:16 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *occ;

	occ = NULL;
	while (*s)
	{
		if (*s == (char)c)
			occ = (char*)s;
		s++;
	}
	if (*s == (char)c)
		occ = (char*)s;
	return (occ);
}
