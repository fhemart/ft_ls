/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 08:41:37 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 09:08:31 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list	*ptr1;
	t_list	*ptr2;

	if (!begin_list)
		return ;
	ptr1 = *begin_list;
	ptr2 = NULL;
	while (*begin_list)
	{
		ptr1 = *begin_list;
		*begin_list = (*begin_list)->next;
		ptr1->next = ptr2;
		ptr2 = ptr1;
		ptr1 = *begin_list;
	}
	*begin_list = ptr2;
}
