/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:53:28 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 09:55:44 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	if (power < 0 || nb > 2147483647 || power > 2147483647)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		nb = nb * ft_power(nb, power - 1);
	return (nb);
}
