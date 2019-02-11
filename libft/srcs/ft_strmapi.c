/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:07:50 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 03:13:21 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*s2;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		if (!(s2 = malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			s2[i] = (*f)(i, s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
