/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:59:01 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 23:00:48 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	eos;
	int		last;

	i = 0;
	last = -1;
	eos = ft_strlen(s) + 1;
	while (i < eos)
	{
		if (s[i] == c)
			last = (int)i;
		i++;
	}
	if (last > -1)
		return ((char*)&s[last]);
	return (0);
}
