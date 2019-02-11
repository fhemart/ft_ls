/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 02:38:52 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 07:32:25 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strwind(const char *s, char c, int *data)
{
	size_t	i;
	size_t	word;
	size_t	pos;

	i = 0;
	word = 0;
	pos = 1;
	if (s && c && data)
	{
		while (s[i])
		{
			if ((s[i - 1] == c || i == 0) && s[i] != c)
			{
				word++;
				data[pos++] = i;
			}
			i++;
			if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
				data[pos++] = i - 1;
		}
		data[0] = word;
	}
}
