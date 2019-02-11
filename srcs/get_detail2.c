/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:00:02 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 21:00:26 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*get_maj(int stmajor, char str[20])
{
	int					i;

	i = 4;
	str[5] = '\0';
	if (stmajor == 0)
		str[i--] = '0';
	while (stmajor != 0)
	{
		str[i] = (stmajor % 10) + 48;
		stmajor = stmajor / 10;
		i--;
	}
	while (i != -1)
	{
		str[i] = ' ';
		i--;
	}
	return (str);
}

char					*get_min(int stmajor, char str[20])
{
	int					i;

	i = 11;
	str[12] = '\0';
	if (stmajor == 0)
		str[i--] = '0';
	while (stmajor != 0)
	{
		str[i] = (stmajor % 10) + 48;
		stmajor = stmajor / 10;
		i--;
	}
	while (i != 5)
	{
		str[i] = ' ';
		i--;
	}
	return (str);
}
