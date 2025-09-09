/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:31:19 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:18:35 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
	while (*s)
	{
		new_str[i] = f(*s);
		s++;
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
