/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 21:10:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:27:14 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			resetpath(t_path *path, t_stack **fstack)
{
	path->total = 0;
	path->f3len = 0;
	path->f4len = 0;
	path->f5len = 0;
	*fstack = NULL;
}

static int			besmart(t_env *env, t_path *path, t_data **curs)
{
	if (path_check(env, env->stack, path) == -1)
		return (-1);
	env->start = 1;
	if (path->data && !(ETIME))
		path->data = ft_sort_list(path->data, ft_sort_ascii_str);
	if (path->data && ETIME)
		path->data = ft_sort_list(path->data, ft_sort_dr_int);
	if (path->data && env->flags & REV)
		ft_lstrev1(&path->data);
	if (*curs && ELIST)
	{
		ft_smax_add(env->smax, "total ");
		ft_smax_add(env->smax,
			(const char *)ft_strcat(get_total(path->total), "\n"));
	}
	return (0);
}

static void			printdetail(t_data **curs, t_env *env, t_path *path,
	char *temp)
{
	ft_smax_add(env->smax, (const char *)(*curs)->f1a);
	ft_smax_add(env->smax, " ");
	ft_smax_add(env->smax, (const char *)(*curs)->f2);
	ft_smax_add(env->smax, env->space + (17 - (path->f3len - (*curs)->f3len)));
	ft_smax_add(env->smax, (const char *)(*curs)->f3);
	ft_smax_add(env->smax, env->space + (18 - (path->f4len - (*curs)->f4len)));
	ft_smax_add(env->smax, (const char *)(*curs)->f4);
	ft_smax_add(env->smax, env->space + (17 - (path->f5len - (*curs)->f5len)));
	ft_smax_add(env->smax, (const char *)(*curs)->f5);
	ft_smax_add(env->smax, "  ");
	ft_smax_add(env->smax, (const char *)(*curs)->f6a);
	ft_smax_add(env->smax, "  ");
	if ((temp = ft_strchrend((*curs)->f7, '/')) != NULL)
	{
		if (((*curs)->f1a)[0] == 'l')
			ft_strcpy((*curs)->f7, get_link((*curs)->f7));
		ft_smax_add(env->smax, temp + 1);
	}
	else
	{
		if (((*curs)->f1a)[0] == 'l')
			ft_strcpy((*curs)->f7, get_link((*curs)->f7));
		ft_smax_add(env->smax, (*curs)->f7);
	}
	ft_smax_add(env->smax, "\n");
}

static void			printloop(t_data **curs, t_env *env, t_path *path,
	t_stack **fstack)
{
	t_data			*tmp;
	char			*temp;

	while (*curs)
	{
		if (EREC && is_point((*curs)->f7) != 1 &&
			((*curs)->f1 & (S_IFDIR)) != 0)
			if (push_stack(fstack, (*curs)->f7, 0))
				exit(-1);
		if (!(ELIST))
		{
			if ((temp = ft_strchrend((*curs)->f7, '/')) != NULL)
				ft_smax_add(env->smax, temp + 1);
			else
				ft_smax_add(env->smax, (*curs)->f7);
			ft_smax_add(env->smax, "\n");
		}
		else
			printdetail(curs, env, path, temp);
		tmp = (*curs)->next;
		free(*curs);
		(*curs) = tmp;
	}
}

int					print_path(t_env *env)
{
	t_stack			*fstack;
	t_path			path;
	t_data			**curs;

	path.data = NULL;
	fstack = NULL;
	while (env->stack)
	{
		resetpath(&path, &fstack);
		if (besmart(env, &path, curs) == -1)
			return (-1);
		curs = &path.data;
		printloop(curs, env, &path, &fstack);
		if (env->stack->next || fstack)
			ft_smax_add(env->smax, "\n");
		ft_smax_wclose(&env->smax);
		join_stack(&fstack, &env->stack);
	}
	return (0);
}
