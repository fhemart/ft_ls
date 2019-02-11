/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:52:24 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:14:51 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			checkopt(t_env *env, char *opt)
{
	static char		optflags[MAX_FLAGS] = {ALL_FLAGS};
	int				i;

	opt++;
	while (*opt)
	{
		i = -1;
		while (++i < MAX_FLAGS)
		{
			if (*opt == optflags[i])
			{
				if (env->flags & (1 << i))
					break ;
				env->flags = env->flags | (1 << i);
				break ;
			}
		}
		if (i == MAX_FLAGS)
			return ((int)*opt);
		opt++;
	}
	return (-1);
}

static void			usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ft_ls [-lRart] [file ...]");
}

int					ft_opt_get(t_env *env, int argc, char **argv)
{
	int				i;
	int				y;

	i = 1;
	y = 0;
	if (argc == 1)
		return (i);
	while (i < argc && (argv[i][0] == '-' && argv[i][1] != '\0'))
	{
		if (argv[i][1] == '-')
			return (++i);
		y = checkopt(env, argv[i]);
		if (y >= 0)
			return (y + 1000);
		i++;
	}
	return (i);
}

int					opt_engine(t_env *env, int argc, char **argv)
{
	int i;

	i = 0;
	env->flags = 0;
	i = ft_opt_get(env, argc, argv);
	if (i >= 1000)
	{
		usage(i - 1000);
		return (-1);
	}
	return (i);
}
