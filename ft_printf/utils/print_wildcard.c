/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:41:47 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:41:49 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wildcard(t_flags flags, int *n_char)
{
	int			padding;

	if ((padding = flags.width - 1) < 0)
		padding = 0;
	if (flags.zero)
	{
		print_width(n_char, padding, '0');
		write(1, "%", 1);
		*n_char += 1;
	}
	else
	{
		if (!flags.minus)
			print_width(n_char, padding, ' ');
		write(1, "%", 1);
		*n_char += 1;
		if (flags.minus)
			print_width(n_char, padding, ' ');
	}
}
