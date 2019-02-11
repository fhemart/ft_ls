/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:43:44 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 04:08:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(s = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s1[j])
		{
			s[i++] = s1[j++];
		}
		j = 0;
		while (s2[j])
		{
			s[i++] = s2[j++];
		}
		s[i] = '\0';
		return (s);
	}
	return (NULL);
}
