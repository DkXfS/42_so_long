/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:42:32 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:42:35 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_minus(const char **in, t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	(*in)++;
}

void		set_zero(const char **in, t_flags *flags)
{
	if (!(flags->minus))
		flags->zero = 1;
	(*in)++;
}

void		set_star(const char **in, va_list ap, t_flags *flags)
{
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
		if (flags->zero)
			flags->zero = 0;
	}
	(*in)++;
}

void		set_width(const char **in, t_flags *flags)
{
	while (**in >= '0' && **in <= '9')
	{
		flags->width *= 10;
		flags->width += **in - '0';
		(*in)++;
	}
}

void		set_precision(const char **in, va_list ap, t_flags *flags)
{
	flags->precision = 0;
	(*in)++;
	if (**in == '*')
	{
		flags->precision = va_arg(ap, int);
		(*in)++;
	}
	else if (**in >= '0' && **in <= '9')
	{
		while (**in >= '0' && **in <= '9')
		{
			flags->precision *= 10;
			flags->precision += **in - '0';
			(*in)++;
		}
	}
	else
		flags->only_dot = 1;
}
