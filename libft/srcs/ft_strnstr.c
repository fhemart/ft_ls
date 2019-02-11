/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:42:13 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 06:27:38 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(need) < 1)
		return ((char*)&s[0]);
	while (s[i] && len-- >= ft_strlen(need))
	{
		if (s[i] == need[j])
		{
			if (ft_memcmp((void*)&s[i], (void*)need, ft_strlen(need)) == 0)
			{
				return ((char*)s + i);
			}
		}
		i++;
	}
	return (0);
}
