/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:02:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/24 19:50:29 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(void **begin_list)
{
	size_t	i;
	t_list	**lst;

	lst = ((t_list**)(begin_list));
	i = 0;
	while (*lst)
	{
		i++;
		lst = &(*lst)->next;
	}
	return (i);
}
