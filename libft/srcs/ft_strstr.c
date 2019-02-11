/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:13:33 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/09 22:56:32 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s, const char *need)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(need) < 1)
		return ((char*)&s[0]);
	while (s[i] && j < ft_strlen(need))
	{
		if (s[i] == need[j])
		{
			if (ft_strncmp(&s[i], need, ft_strlen(need)) == 0)
				return ((char*)&s[i]);
		}
		i++;
	}
	return (0);
}
