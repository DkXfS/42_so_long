/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:04:54 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:05:32 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_equals(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	sub_strlen(char const *s, char const *set)
{
	size_t len;

	len = 0;
	while (char_equals(*s, set))
		s++;
	while (*s)
	{
		len++;
		s++;
	}
	s--;
	while (char_equals(*s, set))
	{
		s--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*subs;
	char	*temp;
	size_t	len;

	while (char_equals(*s1, set))
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	len = sub_strlen(s1, set);
	if (!(subs = (char*)malloc(len + 1)))
		return (subs);
	temp = subs;
	while (len)
	{
		*subs = *s1;
		len--;
		s1++;
		subs++;
	}
	*subs = 0;
	return (temp);
}
