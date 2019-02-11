/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:23:41 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 22:53:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	eos;

	i = 0;
	eos = ft_strlen(s) + 1;
	while (i < eos)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	return (0);
}
