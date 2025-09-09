/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:28:35 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 12:11:44 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t		sub_strlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && c != *s)
	{
		s++;
		len++;
	}
	return (len + 1);
}

static int			word_num(char const *s, char c)
{
	int count;
	int in_split;

	in_split = 0;
	while (*s && *s == c)
		s++;
	count = 0;
	while (*s)
	{
		if (!in_split || *s == c || *(s + 1) == 0)
		{
			count++;
			in_split = 1;
		}
		else if (*s != c)
			in_split = 0;
		s++;
	}
	return (count + 1);
}

static const char	*substr_copy(char const *s, char *dest, char c)
{
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		*dest = *s;
		dest++;
		s++;
	}
	*dest = 0;
	return (--s);
}

char				**ft_split(char const *s, char c)
{
	char	**arr;
	char	**temp;

	if (!(arr = (char**)malloc(word_num(s, c) * sizeof(char*))))
		return (arr);
	temp = arr;
	while (*s)
	{
		if (*s != c)
		{
			if (!(*arr = (char*)malloc(sub_strlen(s, c) * sizeof(char))))
				return (NULL);
			s = substr_copy(s, *arr, c);
			arr++;
		}
		s++;
	}
	*arr = NULL;
	return (temp);
}
