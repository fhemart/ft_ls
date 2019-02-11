/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:16:35 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 08:40:59 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t len)
{
	size_t	index;
	size_t	i;
	size_t	s1len;

	i = 0;
	index = ft_strlen(s1);
	s1len = index;
	if (s1len >= len)
		return (ft_strlen(s2) + len);
	while (s2[i] && i < (len - s1len - 1))
	{
		s1[index] = s2[i];
		index++;
		i++;
	}
	s1[index] = '\0';
	return (s1len + ft_strlen(s2));
}
