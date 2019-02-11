/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:48:11 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/11 20:48:28 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_checkopt(t_env **env, char *opt)
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

void				usage(t_env **env, char c)
{
	free(*env);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ft_ls [-lRart] [file ...]");
}

int					ft_opt_get(t_env **env, int argc, char **argv)
{
	int				i;
	int				y;

	i = 1;
	y = 0;
	if (argc == 1)
		return (i);
	while (i < argc && (argv[i][0] == '-' && argv[i][1] != '\0'))
	{
		y = ft_checkopt(env, argv[i]);
		if (y >= 0)
			return (y + 1000);
		i++;
	}
	return (i);
}
int					opt_engine(t_env **env, int argc, char **argv)
{
	int i;

	i = 0;
	(*env)->flags = 0;
	i = ft_opt_get(env, argc,argv);
	if (i >= 1000)
	{
		usage(env, i - 1000);
		return (-1);
	}
	return (i);
}

int				ft_path_exist(char *path)
{
	struct stat sb;

	if (lstat(path,& sb) == -1)
	{
		ft_putstr("ls: ");
		if (path[0] == '\0')
			ft_putstr("fts_open");
		else
			ft_putstr(path);
		perror(" ");
		return (0);
	}
	return (sb.st_mode);
}

int				ft_path_check(int st_mode)
{
	return (((st_mode & (S_IFDIR)) != 0) ? 1: 0);
}

int				ft_path_fill(t_env **env, int i, int argc, char **argv)
{
	int st_mode;

	*env = *env;
	if (i == argc)
		printf("path = . i=%d argc=%d\n", i, argc);
		//ft_path_add_d(path) sinon ret-1
	else
	{
		while (i < argc)
		{
			printf("path0 = %s\n",argv[i]);
			if((st_mode = ft_path_exist(argv[i])) != 0)
				printf("path_check = %d\n",ft_path_check(st_mode));
			i++;
//			printf("i = %d\n",i);
			//if (argv[i][0] =='\0')
			//	print fts_open...
			//	return (-1)
			//if file ft_path_add_f set path->sb = NULL sinon ret-1
			//else ft_path_add_d(path) sinon ret-1
		}
	}
	return (1);
}

int					main(int argc, char **argv)
{
	t_env			*env;
	int				i;

	i = 0;
	if (!(env = malloc(sizeof(t_env))))
		return (-1);
	env->path = NULL;
	if ((i = opt_engine(&env, argc, argv)) == -1)
		return (1);
	printf("i = %d\n",i);
	printf("argc = %d\n",argc);
	ft_path_fill(&env, i, argc, argv);
//	if (argv[i][0] == '\0')
//		printf("fts_open= %s\n",argv[i]);
	return (0);
}
