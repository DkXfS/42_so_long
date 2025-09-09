/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:43:48 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:44:50 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_pow(nb, power - 1));
}

void	str_reverse(char *s, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
}

int		int_to_str(uint64_t n, char s[], int precision)
{
	int	i;

	i = 0;
	if (n == 0)
		s[i++] = '0';
	while (n)
	{
		s[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i < precision)
		s[i++] = '0';
	str_reverse(s, i);
	s[i] = 0;
	return (i);
}

char	*ft_ftoa(long double n, char *s, t_flags f)
{
	uint64_t	ipart;
	long double	fpart;
	int			i;

	ipart = (uint64_t)n;
	fpart = n - (long double)ipart;
	if (f.precision == 0 && fpart >= 0.5)
		if ((ipart % 2 == 1) || (fpart > 0.5))
			ipart += 1;
	i = int_to_str(ipart, s, 0);
	if (f.precision == 0 && f.hash)
	{
		s[i++] = '.';
		s[i] = 0;
	}
	if (f.precision != 0)
	{
		s[i++] = '.';
		ipart = fpart * ft_pow(10, f.precision + 1);
		if (ipart % 10 > 4)
			ipart += 10;
		int_to_str(ipart / 10, s + i, f.precision);
	}
	return (s);
}
