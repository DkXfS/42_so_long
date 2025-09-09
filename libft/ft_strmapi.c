/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:51:56 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 13:20:43 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 1;
	new_str = (char*)s;
	while (*s)
	{
		s++;
		i++;
	}
	s = new_str;
	if (!(new_str = (char*)malloc(i * sizeof(char))))
		return (new_str);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
