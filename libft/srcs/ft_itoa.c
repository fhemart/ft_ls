/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:17:51 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/11 23:07:35 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t		len;
	size_t		neg;

	len = 0;
	neg = 0;
	(n < 0) ? neg = 1 : neg;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	(len > 0) ? len : len++;
	return (len + neg);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long		n2;

	n2 = (long)n;
	i = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * ft_intlen(n) + 1)))
		return (NULL);
	if (n2 < 0)
	{
		str[0] = '-';
		n2 = n2 * -1;
	}
	str[i] = '\0';
	i--;
	while (n2 > 9)
	{
		str[i] = (n2 % 10) + 48;
		n2 = n2 / 10;
		i--;
	}
	str[i] = n2 + 48;
	return (str);
}
