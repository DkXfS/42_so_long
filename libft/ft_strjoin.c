/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:50:16 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/14 15:50:18 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *join;
	char *start;

	join = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	start = join;
	if (join)
	{
		while (*s1)
		{
			*join = *s1;
			join++;
			s1++;
		}
		while (*s2)
		{
			*join = *s2;
			join++;
			s2++;
		}
		*join = 0;
	}
	return (start);
}
