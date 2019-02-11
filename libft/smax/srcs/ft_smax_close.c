/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:12:15 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:41 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

void			ft_smax_close(t_str **smax)
{
	t_str		*tmp;

	while (*smax)
	{
		tmp = (*smax);
		(*smax) = (*smax)->next;
		free(tmp);
		tmp = NULL;
	}
}
