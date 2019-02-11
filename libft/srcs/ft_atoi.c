/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:46:46 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 02:32:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	nb = 0;
	i = 0;
	neg = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && neg == 0)
	{
		(str[i] == '-') ? neg++ : neg--;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		nb = (nb * 10) + (str[i++] - 48);
	}
	return ((neg > 0) ? nb * -1 : nb);
}
