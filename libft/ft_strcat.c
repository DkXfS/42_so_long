/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apanthap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:10:29 by apanthap          #+#    #+#             */
/*   Updated: 2021/01/16 15:10:45 by apanthap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	char *temp;

	temp = dest;
	while (*dest != 0)
		dest++;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (temp);
}
