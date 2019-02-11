/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_wclose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:11:41 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:28:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

void			ft_smax_wclose(t_str **smax)
{
	t_str		*tmp;
	t_str		*curs;

	curs = (*smax)->next;
	write(1, (*smax)->str, (*smax)->len);
	while (curs)
	{
		tmp = curs;
		write(1, curs->str, curs->len);
		curs = curs->next;
		free(tmp);
		tmp = NULL;
	}
	ft_bzero((void *)(*smax)->str, S_MAX + 1);
	(*smax)->len = 0;
	(*smax)->next = NULL;
}
