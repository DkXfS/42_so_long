/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:59:08 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:04:28 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	support_print(int n, int fd)
{
	int i;

	if (n)
	{
		i = n % 10;
		if (i < 0)
			i = -i;
		support_print(n /= 10, fd);
		ft_putchar_fd('0' + i, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (!n)
		write(fd, "0", 1);
	else
		support_print(n, fd);
}
