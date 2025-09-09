/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:42:08 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:42:12 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkflags_hex(t_flags *flags, int numlen, int n_char, unsigned int val)
{
	if (flags->hash && !val)
		flags->hash = 0;
	if (flags->zero && flags->precision > -1)
		flags->zero = 0;
	if (flags->zero && flags->width > (numlen + flags->hash))
	{
		flags->zero = flags->width - (numlen + flags->hash);
		flags->width = 0;
	}
	else
		flags->zero = 0;
	if (flags->precision > numlen)
		flags->zero = flags->precision - numlen;
	if (flags->width > (flags->zero + numlen + flags->hash))
		flags->width -= (flags->zero + (numlen + flags->hash));
	else
		flags->width = 0;
	return (n_char);
}

int		hexlen(unsigned long val)
{
	int numlen;

	if (!val)
		return (1);
	numlen = 0;
	while (val)
	{
		numlen += 1;
		val /= 16;
	}
	return (numlen);
}

void	printnum(unsigned long val, char alphacase, int *len, int toprint)
{
	char digit;

	if (val && toprint)
	{
		digit = "0123456789abcdef"[val % 16];
		val /= 16;
		if ((digit >= 'a' && digit <= 'f') && alphacase == 'X')
			digit -= 32;
		printnum(val, alphacase, len, toprint);
		write(1, &digit, 1);
		(*len)++;
	}
}

int		hash_case(int len, t_flags flags, char alphacase)
{
	if (flags.hash)
	{
		if (alphacase == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		len += 2;
	}
	return (len);
}

void	printhex(unsigned int val, char alphacase, int *len, t_flags flags)
{
	int numlen;

	numlen = hexlen((unsigned long)val);
	if (!val && flags.precision > -1)
		numlen = 0;
	if ((*len = checkflags_hex(&flags, numlen, *len, val)) == -1)
		return ;
	*len += (flags.width + flags.zero);
	if (!flags.minus)
		while (flags.width--)
			write(1, " ", 1);
	*len = hash_case(*len, flags, alphacase);
	while (flags.zero--)
		write(1, "0", 1);
	if (!val && numlen)
	{
		write(1, "0", 1);
		(*len)++;
	}
	else
		printnum((unsigned long)val, alphacase, len, numlen);
	if (flags.minus)
		while (flags.width--)
			write(1, " ", 1);
}
