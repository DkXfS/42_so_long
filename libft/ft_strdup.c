/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:06:37 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 13:06:59 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;
	char *temp;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (dup);
	temp = dup;
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = 0;
	return (temp);
}
