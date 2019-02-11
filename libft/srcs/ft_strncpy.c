/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:10:26 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 22:55:36 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (src[j] == '\0')
		{
			dest[i] = '\0';
			i++;
		}
		else
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	return (dest);
}
