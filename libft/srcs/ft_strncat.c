/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:02:40 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 22:55:03 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t len)
{
	size_t	s1len;
	size_t	i;

	i = 0;
	s1len = ft_strlen(s1);
	while (s2[i] && i < len)
	{
		s1[s1len] = s2[i];
		s1len++;
		i++;
	}
	s1[s1len] = '\0';
	return (s1);
}
