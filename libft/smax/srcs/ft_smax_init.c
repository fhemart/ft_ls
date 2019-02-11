/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smax_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 20:09:06 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:27:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/smax.h"

t_str			*ft_smax_init(const char *str)
{
	t_str		*smax;

	if (!(smax = malloc(sizeof(t_str))))
		return (NULL);
	smax->next = NULL;
	ft_bzero((void *)smax->str, S_MAX + 1);
	smax->len = 0;
	if (str != NULL)
	{
		if (ft_smax_add(smax, str) == -1)
		{
			ft_smax_close(&smax);
			return (NULL);
		}
	}
	return (smax);
}
