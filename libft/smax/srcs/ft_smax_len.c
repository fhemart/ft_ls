/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:10:49 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:49 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

size_t			ft_smax_len(t_str *smax)
{
	size_t		len;

	len = 0;
	while (smax)
	{
		len = len + smax->len;
		smax = smax->next;
	}
	return (len);
}
