/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:39:55 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:39:58 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hash(const char **in, t_flags *flags)
{
	flags->hash = 2;
	(*in)++;
}

void	set_space(const char **in, t_flags *flags)
{
	if (!flags->plus)
		flags->space = 1;
	(*in)++;
}

void	set_plus(const char **in, t_flags *flags)
{
	flags->plus = 1;
	flags->space = 0;
	(*in)++;
}
