/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:28:57 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 03:43:30 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s)
	{
		if (!(s2 = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			s2[i] = s[start + i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
