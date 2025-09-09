/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:08:48 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:08:15 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new_str;
	char *str_start;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	new_str = (char*)malloc(len + 1);
	if (!new_str)
		return (new_str);
	str_start = new_str;
	ft_bzero((void*)new_str, len + 1);
	while (start)
	{
		s++;
		start--;
	}
	while (len)
	{
		*new_str = *s;
		new_str++;
		s++;
		len--;
	}
	return (str_start);
}
