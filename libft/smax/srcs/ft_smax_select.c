/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:13:01 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

t_str			*ft_smax_select(t_str *smax)
{
	t_str		*curs;

	curs = smax;
	while (curs->next)
		curs = curs->next;
	return (curs);
}
