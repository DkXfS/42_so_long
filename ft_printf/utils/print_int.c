/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:41:19 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:41:21 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_intsign(int *n_char, t_flags flags, int minus)
{
	if (minus)
		print_width(n_char, 1, '-');
	else if (flags.plus)
		print_width(n_char, 1, '+');
	else if (flags.space)
		print_width(n_char, 1, ' ');
}

void	print_width(int *n_char, int n, char c)
{
	while (n--)
	{
		write(1, &c, 1);
		(*n_char)++;
	}
}

void	print_no_p(int n, t_flags flags, int *n_char, int n_len)
{
	int			minus;
	int			padding;

	minus = n < 0;
	if ((padding = flags.width - n_len -
				(minus || flags.plus || flags.space)) < 0)
		padding = 0;
	if (flags.zero)
	{
		print_intsign(n_char, flags, minus);
		print_width(n_char, padding, '0');
		ft_put_abs_nbr(n);
		*n_char += n_len;
	}
	else
	{
		if (!flags.minus)
			print_width(n_char, padding, ' ');
		print_intsign(n_char, flags, minus);
		ft_put_abs_nbr(n);
		*n_char += n_len;
		if (flags.minus)
			print_width(n_char, padding, ' ');
	}
}

void	print_with_p(int n, t_flags flags, int *n_char, int n_len)
{
	int			minus;
	int			zeros;
	int			spaces;

	minus = n < 0;
	if ((zeros = flags.precision - n_len) < 0)
		zeros = 0;
	if ((spaces = flags.width - n_len - zeros -
				(minus || flags.plus || flags.space)) < 0)
		spaces = 0;
	if (!flags.minus)
		print_width(n_char, spaces, ' ');
	print_intsign(n_char, flags, minus);
	print_width(n_char, zeros, '0');
	if (!(n == 0 && flags.precision == 0))
		ft_put_abs_nbr(n);
	*n_char += n_len;
	if (flags.minus)
		print_width(n_char, spaces, ' ');
}

void	print_int(int n, t_flags flags, int *n_char)
{
	int			n_len;

	n_len = ft_nbrlen(n, flags.precision);
	if (flags.precision != -1)
		print_with_p(n, flags, n_char, n_len);
	else
		print_no_p(n, flags, n_char, n_len);
}
