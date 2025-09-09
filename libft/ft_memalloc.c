/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:08:34 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:08:55 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*rtrn;
	void	*temp;
	size_t	i;

	i = 0;
	rtrn = (char*)malloc(size);
	temp = (void*)rtrn;
	if (rtrn)
	{
		while (i < size)
		{
			*rtrn = 0;
			i++;
			rtrn++;
		}
	}
	return (temp);
}
