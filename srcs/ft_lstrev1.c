/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:31:25 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 15:25:23 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstrev1(t_data **begin_list)
{
	t_data	*ptr1;
	t_data	*ptr2;

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
