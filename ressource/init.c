/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:29:09 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/10 21:58:11 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_checkopt(t_env **env, char *opt)
{
	static char		optflags[MAX_FLAGS] = {ALL_FLAGS};
	int				i;

	(*env)->flags = 0;
	if ((*opt && *(opt++) != '-') || *opt == '\0')
		return (-2);
	while (*opt)
	{
		i = -1;
		while (++i < MAX_FLAGS)
		{
			if (*opt == optflags[i])
			{
				if ((*env)->flags & (1 << i))
					break ;
				(*env)->flags = (*env)->flags | (1 << i);
				break ;
			}
		}
		if (i == MAX_FLAGS)
			return ((int)*opt);
		opt++;
	}
	return (-1);
}

t_env				*ft_freepath(t_path **path, t_env **env)
{
	t_path			*curs;
	t_path			*tmp;

	if ((*path)->next)
	{
		curs = (*path)->next;
		while (curs)
		{
			tmp = curs;
			curs = curs->next;
			free(tmp);
			tmp = NULL;
		}
	}
	if (*path)
		free(*path);
	*path = NULL;
	if (*env)
		free(*env);
	*env = NULL;
	return (NULL);
}

t_env				*ft_addpath(t_env **env, char *str)
{
	t_path			*curs;

	if ((*env)->path == NULL)
	{
		if (!((*env)->path = malloc(sizeof(t_path))))
			return (ft_freepath(&(*env)->path, env));
		curs = (*env)->path;
	}
	else
	{
		curs = (*env)->path;
		while (curs->next != NULL)
			curs = curs->next;
		if (!(curs->next = malloc(sizeof(t_path))))
			return (ft_freepath(&(*env)->path, env));
		curs = curs->next;
	}
	curs->data = NULL;
	curs->next = NULL;
	curs->path = str;
	return (*env);
}

t_env				*usage(t_env **env, char c)
{
	free(*env);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ft_ls [-lRart] [file ...]");
	return (NULL);
}

t_env				*ft_init(int argc, char **argv)
{
	t_env			*env;
	size_t			i;
	int				ret;

	i = 1;
	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->path = NULL;
//	ret = (argc > 1) ? ft_checkopt(&env, argv[1]) : 0;
	ret = ft_get_opt(argv, argc, &env);
//	ret = -1;
	if (ret >= 1000)
		return (usage(&env, ret - 1000));
//	if (argc == 1 || (argc == 2 && ret == -1))
//		return (ft_addpath(&env, "."));
//	else if (argc == 2)
//		return (ft_addpath(&env, argv[ret]));
//	else if (argc > 2)
//	{
//		if (ret == -1)
//			i = 2;
		while (ret < argc)
		{
			printf("i=%d\n",ret);
			if (!ft_addpath(&env, argv[ret++]))
				return (NULL);
		}
//	}
	return (env);
}
