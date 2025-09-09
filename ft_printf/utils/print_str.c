/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:40:57 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:41:04 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printspaces(int len, ssize_t spacenum)
{
	while (spacenum)
	{
		write(1, " ", 1);
		len++;
		spacenum--;
	}
	return (len);
}

void	check_flags(t_flags *dat, ssize_t *strlen)
{
	if (dat->width < 0)
	{
		dat->width *= -1;
		dat->minus = 1;
	}
	if (dat->precision > -1)
	{
		if (dat->precision < *strlen)
			*strlen = dat->precision;
	}
}

void	print_str(char *s, t_flags dat, int *len)
{
	ssize_t		spaces;
	ssize_t		strlen;

	if (!s)
	{
		s = "(null)";
	}
	strlen = ft_strlen(s);
	check_flags(&dat, &strlen);
	if ((spaces = dat.width - strlen) < 0)
		spaces = 0;
	if (!dat.minus)
		*len = printspaces(*len, spaces);
	while (strlen--)
	{
		write(1, s++, 1);
		(*len)++;
	}
	if (dat.minus)
		*len = printspaces(*len, spaces);
}
