/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:28:21 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/17 10:33:19 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*p_dest;
	char			*p_src;
	unsigned int	n;
	unsigned int	dlen;

	p_dest = dest;
	p_src = src;
	n = size;
	while (n-- != 0 && *p_dest != '\0')
		p_dest++;
	dlen = p_dest - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(p_src));
	while (*p_src)
	{
		if (n != 1)
		{
			*p_dest++ = *p_src;
			n--;
		}
		p_src++;
	}
	*p_dest = '\0';
	return (dlen + (p_src - src));
}
