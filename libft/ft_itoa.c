/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:56:13 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 12:27:50 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	numlen(int n)
{
	int i;

	i = 0;
	if (!n)
		return (1);
	if (n < 0)
		i = 1;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*n_str;
	int		count;
	int		digit;

	count = numlen(n);
	if ((n_str = (char*)malloc((count + 1) * sizeof(char))))
	{
		n_str[count--] = 0;
		if (!n)
		{
			n_str[count] = '0';
			return (n_str);
		}
		while (n)
		{
			if ((digit = n % 10) < 0)
				digit = -digit;
			n_str[count--] = '0' + digit;
			n /= 10;
		}
		if (count == 0)
			n_str[count] = '-';
	}
	return (n_str);
}
