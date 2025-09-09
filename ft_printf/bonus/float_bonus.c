/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:40:25 by apanthap          #+#    #+#             */
/*   Updated: 2021/02/08 11:40:27 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s1)
{
	char			*d;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	if (!(d = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i <= len)
	{
		d[i] = s1[i];
		i++;
	}
	return (d);
}

void	print_with_f(long double n, char *ns, t_flags flags, int *n_char)
{
	int			minus;
	int			i;
	int			n_len;

	i = 0;
	minus = n < 0;
	n_len = ft_strlen(ns);
	flags.width = flags.width - n_len - (minus || flags.plus || flags.space);
	if (flags.width < 0)
		flags.width = 0;
	if (!flags.minus && !flags.zero)
		print_width(n_char, flags.width, ' ');
	print_intsign(n_char, flags, minus);
	if (flags.zero)
		print_width(n_char, flags.width, '0');
	while (i < n_len)
		write(1, &ns[i++], 1);
	if (flags.minus)
		print_width(n_char, flags.width, ' ');
	*n_char += n_len;
}

void	check_infnan(long double n, char **ns, t_flags *f)
{
	if (n != n)
	{
		free(*ns);
		*ns = ft_strdup("nan");
		f->zero = 0;
	}
	else if (n == 1.0 / 0 || n == -1.0 / 0)
	{
		free(*ns);
		*ns = ft_strdup("inf");
		f->zero = 0;
	}
}

void	print_float(long double n, t_flags f, int *n_char)
{
	char	*ns;

	if (!(ns = malloc(sizeof(char) * 100)))
	{
		*n_char = -1;
		return ;
	}
	if (f.precision == -1)
		f.precision = 6;
	if (n != n || n == 1.0 / 0 || n == -1.0 / 0)
		check_infnan(n, &ns, &f);
	else if (n < 0)
		ft_ftoa((n * -1), ns, f);
	else
		ft_ftoa(n, ns, f);
	print_with_f(n, ns, f, n_char);
	free(ns);
}
