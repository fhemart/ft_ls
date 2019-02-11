/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:21:52 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 03:09:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if ((*alst) && (del))
	{
		while (*alst)
		{
			tmp = (*alst);
			(del)((*alst)->content, (*alst)->content_size);
			(*alst) = (*alst)->next;
			free(tmp);
		}
		(*alst) = NULL;
	}
}
