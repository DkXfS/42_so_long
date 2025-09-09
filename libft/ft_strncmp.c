/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:18:17 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/15 14:18:20 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 != 0 && *s2 != 0 && *s1 == *s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
