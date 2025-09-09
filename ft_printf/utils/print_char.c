/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:40:43 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:40:46 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, t_flags flags, int *n_char)
{
	if (flags.zero || flags.precision != -1)
		*n_char = -1;
	else
	{
		if (flags.width)
		{
			if (flags.minus)
				write(1, &c, 1);
			while (--flags.width)
			{
				write(1, " ", 1);
				(*n_char)++;
			}
			if (!flags.minus)
				write(1, &c, 1);
			(*n_char)++;
		}
		else
		{
			write(1, &c, 1);
			(*n_char)++;
		}
	}
}
