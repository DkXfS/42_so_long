/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:41:32 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:41:35 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ulen(unsigned int n, t_flags flags)
{
	int		len;

	len = 0;
	if (n == 0 && flags.precision != 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	print_u_no_p(unsigned int n, t_flags flags, int *n_char, int n_len)
{
	int			padding;

	if ((padding = flags.width - n_len) < 0)
		padding = 0;
	if (flags.zero)
	{
		print_width(n_char, padding, '0');
		ft_put_unsigned(n);
		*n_char += n_len;
	}
	else
	{
		if (!flags.minus)
			print_width(n_char, padding, ' ');
		ft_put_unsigned(n);
		*n_char += n_len;
		if (flags.minus)
			print_width(n_char, padding, ' ');
	}
}

void	print_u_with_p(unsigned int n, t_flags flags, int *n_char, int n_len)
{
	int			zeros;
	int			spaces;

	if ((zeros = flags.precision - n_len) < 0)
		zeros = 0;
	if ((spaces = flags.width - n_len - zeros) < 0)
		spaces = 0;
	if (!flags.minus)
		print_width(n_char, spaces, ' ');
	print_width(n_char, zeros, '0');
	if (!(n == 0 && flags.precision == 0))
		ft_put_unsigned(n);
	*n_char += n_len;
	if (flags.minus)
		print_width(n_char, spaces, ' ');
}

void	print_unsigned(unsigned int n, t_flags flags, int *n_char)
{
	int			n_len;

	n_len = ft_ulen(n, flags);
	if (flags.minus && flags.zero)
	{
		*n_char = -1;
		return ;
	}
	if (flags.precision != -1)
		print_u_with_p(n, flags, n_char, n_len);
	else
		print_u_no_p(n, flags, n_char, n_len);
}
