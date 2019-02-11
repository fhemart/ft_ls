/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 01:23:52 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 22:50:45 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t	i;
	char	*c1;
	char	*c2;

	c1 = (char*)s1;
	c2 = (char*)s2;
	if (len == 0)
		return (0);
	i = 0;
	while (c1[i] == c2[i] && i + 1 < len)
	{
		i++;
	}
	return ((unsigned char)c1[i] - (unsigned char)c2[i]);
}
