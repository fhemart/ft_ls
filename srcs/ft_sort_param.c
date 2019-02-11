/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:15:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 15:25:34 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_sort_cr_int(int a, int b)
{
	return (a - b);
}

int					ft_sort_dr_int(int a, int b, char *s1, char *s2)
{
	if (a == b)
		return (ft_sort_ascii_str(0, 0, s1, s2));
	return (b - a);
}

int					ft_sort_ascii_str(int a, int b, char *s1, char *s2)
{
	(void)a;
	(void)b;
	return (ft_strcmp(s1, s2));
}

void				ft_sort_param(char ***param, int start, int stop,
							int (*cmp)(int, int, char *, char *))
{
	int				i;
	char			*tmp;

	i = start;
	while (i < stop && (i + 1) < stop)
	{
		if (!(*cmp)(0, 0, (*param)[i], (*param)[i + 1]))
		{
			tmp = (*param)[i];
			(*param)[i] = (*param)[i + 1];
			(*param)[i + 1] = tmp;
			i = start - 1;
		}
		i++;
	}
}
