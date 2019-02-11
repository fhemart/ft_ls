/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 00:45:47 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:33:41 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data		*ft_sort_list(t_data *lst, int (*cmp)())
{
	size_t	tab_size;
	t_data	**tab;
	t_data	*tmp;
	size_t	i;

	i = -1;
	tmp = lst;
	tab_size = ft_lstsize((void**)&lst);
	if (!(tab = malloc(sizeof(t_data *) * tab_size)))
		exit(1);
	while (++i < tab_size)
	{
		tab[i] = tmp;
		tmp = tmp->next;
	}
	return (sort_lst(tab, tab_size, (*cmp)));
}

void		swap(void **elem, void **elem2)
{
	void	*tmp;

	tmp = *elem;
	*elem = *elem2;
	*elem2 = tmp;
}

t_data		*sort_lst(t_data **tab, size_t tab_size, int (*cmp)())
{
	size_t		i;

	i = 0;
	while (++i < tab_size)
	{
		if ((*cmp)(tab[i - 1]->f6, tab[i]->f6, tab[i - 1]->f7, tab[i]->f7) > 0)
		{
			swap((void**)&tab[i], (void**)&tab[i - 1]);
			if (i > 1)
				i -= 2;
			else
				i -= 1;
		}
	}
	return (set_next(tab, tab_size));
}

t_data		*set_next(t_data **tab, size_t tab_size)
{
	int		i;
	t_data	*head;

	i = -1;
	while (++i < (int)tab_size)
	{
		if (i < (int)tab_size - 1)
			tab[i]->next = tab[i + 1];
		else
			tab[i]->next = NULL;
	}
	head = tab[0];
	ft_memdel((void**)&tab);
	return (head);
}
