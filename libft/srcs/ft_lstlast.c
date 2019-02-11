/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:55:20 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 09:07:44 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list	*list;

	if (!begin_list)
		return (NULL);
	list = begin_list;
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}
