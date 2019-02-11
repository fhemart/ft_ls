/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:13:42 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

int				ft_smax_split(t_str *smax, const char *str, size_t strlen)
{
	size_t		i;
	size_t		limit;

	i = 0;
	if (strlen > S_MAX)
		limit = S_MAX;
	else
		limit = S_MAX - (strlen + smax->len);
	while (smax->len + i < limit)
	{
		smax->str[smax->len + i] = str[i];
		i++;
	}
	smax->len = smax->len + i;
	if (!(smax->next = ft_smax_init(str + i)))
		return (-1);
	return (1);
}
