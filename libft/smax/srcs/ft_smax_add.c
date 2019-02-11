/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:45:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:39 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

int				ft_smax_add(t_str *smax, const char *str)
{
	size_t		strlen;
	t_str		*curs;

	curs = ft_smax_select(smax);
	strlen = ft_strlen(str);
	if ((strlen + curs->len) <= S_MAX - curs->len)
	{
		ft_strcpy(curs->str + curs->len, str);
		curs->len = curs->len + strlen;
	}
	else
		return (ft_smax_split(curs, str, strlen));
	return (1);
}
