/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:18:00 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:10:02 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			get_path(t_env *env, int argc, char **argv, int i)
{
	int				ret;

	ret = 0;
	if (argc - i > 1)
		ft_sort_param(&argv, i, argc, ft_sort_ascii_str);
	while (i < argc && ret == 0)
		ret = push_stack(&env->stack, argv[i++], 0);
	if (ret != 0)
		return (-1);
	return (0);
}

static int			parse(t_env *env, int argc, char **argv)
{
	int				i;

	if ((i = opt_engine(env, argc, argv)) == -1)
		return (-1);
	if (i == argc)
		return (push_stack(&env->stack, ".", 0));
	else
		return (get_path(env, argc, argv, i));
	return (0);
}

int					main(int argc, char **argv)
{
	t_env			env;

	env.stack = NULL;
	env.ret = 0;
	env.start = 0;
	ft_memset(env.space, ' ', 20);
	env.space[19] = '\0';
	if (!(env.smax = ft_smax_init(NULL)))
		return (-1);
	if (parse(&env, argc, argv) == -1)
		return (-1);
	if (print_path(&env) == -1)
		return (-1);
	free(env.smax);
	return (env.ret);
}
