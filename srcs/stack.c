/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:49:37 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:14:35 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			join_stack(t_stack **fstack, t_stack **bstack)
{
	t_stack		*tmp;
	t_stack		*curs;

	tmp = (*bstack)->next;
	curs = *fstack;
	free(*bstack);
	*bstack = tmp;
	if (*bstack && *fstack)
	{
		if (*fstack)
		{
			*bstack = *fstack;
			while (curs && curs->next)
				curs = curs->next;
			curs->next = tmp;
		}
	}
	if (!*bstack && *fstack)
		*bstack = *fstack;
}

static int		new_stack(t_stack **stack, char *path)
{
	if (!(*stack = malloc(sizeof(t_stack))))
		return (-1);
	ft_strcpy((*stack)->path, path);
	(*stack)->next = NULL;
	return (0);
}

static int		add_stack(t_stack **stack, char *path, int parent)
{
	t_stack		*curs;

	curs = *stack;
	while (curs->next)
		curs = curs->next;
	if (!(curs->next = malloc(sizeof(t_stack))))
		return (-1);
	if (parent == 1)
	{
		ft_strcpy(curs->next->path, curs->path);
		ft_strlcat(curs->next->path, "/", 4096);
		ft_strlcat(curs->next->path, path, 4096);
	}
	else
		ft_strcpy(curs->next->path, path);
	curs->next->next = NULL;
	return (0);
}

int				push_stack(t_stack **stack, char *path, int parent)
{
	if (!*stack)
		return (new_stack(stack, path));
	return (add_stack(stack, path, parent));
}
