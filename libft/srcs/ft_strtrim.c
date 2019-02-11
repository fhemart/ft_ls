/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:09:12 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 05:08:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	if (s)
	{
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		{
			start++;
			i++;
		}
		if (start == ft_strlen(s))
			return (ft_strnew(1));
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
		}
		return (ft_strsub(s, start, (i - start) + 1));
	}
	return (NULL);
}
