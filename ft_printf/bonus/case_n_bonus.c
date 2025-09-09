/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:55:04 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:55:07 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_len(int *ptr, int *n_char, t_flags flags)
{
	if (flags.width || flags.minus || flags.zero || flags.width || flags.hash
		|| (flags.precision > -1 && !flags.only_dot) || flags.space ||
		flags.plus)
	{
		*n_char = -1;
		return ;
	}
	*ptr = *n_char;
}
