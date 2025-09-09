/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:43:09 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:43:11 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		init_flags(void)
{
	t_flags		flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.only_dot = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

void		print_conv(const char **in, va_list ap, int *n_char, t_flags flags)
{
	if (**in == 'c')
		print_char(va_arg(ap, int), flags, n_char);
	else if (**in == 's')
		print_str(va_arg(ap, char *), flags, n_char);
	else if (**in == 'd' || **in == 'i')
		print_int(va_arg(ap, int), flags, n_char);
	else if (**in == 'p')
		print_ptr(va_arg(ap, void*), n_char, flags);
	else if (**in == 'n')
		save_len(va_arg(ap, int*), n_char, flags);
	else if (**in == 'u')
		print_unsigned(va_arg(ap, unsigned int), flags, n_char);
	else if (**in == 'x' || **in == 'X')
		printhex(va_arg(ap, unsigned int), **in, n_char, flags);
	else if (**in == '%')
		print_wildcard(flags, n_char);
	else if (**in == 'f')
		print_float(va_arg(ap, double), flags, n_char);
	else
		*n_char = -1;
	(*in)++;
}

void		read_flags(const char **in, va_list ap, t_flags *flags)
{
	while (**in == '-' || **in == '0' ||
			**in == '#' || **in == '+' || **in == ' ')
	{
		if (**in == '0')
			set_zero(in, flags);
		if (**in == '-')
			set_minus(in, flags);
		if (**in == '#')
			set_hash(in, flags);
		if (**in == ' ')
			set_space(in, flags);
		if (**in == '+')
			set_plus(in, flags);
	}
	if (**in == '*')
		set_star(in, ap, flags);
	else if (**in >= '1' && **in <= '9')
		set_width(in, flags);
	if (**in == '.')
		set_precision(in, ap, flags);
}

void		print_input(const char **in, va_list ap, int *n_char)
{
	t_flags		flags;

	while (**in)
	{
		if (**in == '%')
		{
			flags = init_flags();
			(*in)++;
			read_flags(in, ap, &flags);
			print_conv(in, ap, n_char, flags);
			if (*n_char == -1)
				return ;
		}
		else
		{
			write(1, (*in)++, 1);
			(*n_char)++;
		}
	}
}

int			ft_printf(const char *input, ...)
{
	va_list		ap;
	int			n_char;

	if (!input)
		return (-1);
	n_char = 0;
	va_start(ap, input);
	print_input(&input, ap, &n_char);
	va_end(ap);
	return (n_char);
}
