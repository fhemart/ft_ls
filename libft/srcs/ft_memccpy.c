/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:06:13 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/13 00:01:16 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, void *src, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		if (((char*)src)[i] == (char)c)
			return (&((char*)dst)[i + 1]);
		i++;
	}
	return (0);
}
