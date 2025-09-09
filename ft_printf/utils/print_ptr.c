/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:46:15 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:46:18 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkflags(t_flags *flags, int numlen, int n_char)
{
	if (flags->zero || (!flags->only_dot && flags->precision > -1))
		return (-1);
	if (flags->width > numlen)
		flags->width -= numlen;
	else
		flags->width = 0;
	return (n_char);
}

void		print_ptr(void *ptr, int *len, t_flags flags)
{
	int numlen;

	if (flags.only_dot && !ptr)
		numlen = 0;
	else
		numlen = hexlen((unsigned long)ptr);
	if ((*len = checkflags(&flags, numlen + 2, *len)) == -1)
		return ;
	(*len) += (flags.width + 2);
	if (!flags.minus)
		while (flags.width--)
			write(1, " ", 1);
	write(1, "0x", 2);
	if (!ptr && !flags.only_dot)
	{
		write(1, "0", 1);
		(*len)++;
	}
	else
		printnum((unsigned long)ptr, 'x', len, 1);
	if (flags.minus)
		while (flags.width--)
			write(1, " ", 1);
}
