/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:45:17 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:45:21 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	divide(int nb)
{
	char n;

	if (nb > 9)
		divide(nb / 10);
	n = nb % 10 + '0';
	write(1, &n, 1);
}

void	ft_put_abs_nbr(int nb)
{
	if (nb == -2147483648)
		write(1, "2147483648", 10);
	else
	{
		if (nb < 0)
			nb = -nb;
		divide(nb);
	}
}

void	ft_put_unsigned(unsigned int nb)
{
	char n;

	if (nb > 9)
		ft_put_unsigned(nb / 10);
	n = nb % 10 + '0';
	write(1, &n, 1);
}
