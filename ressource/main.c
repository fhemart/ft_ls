/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:17:42 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/09 17:23:41 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_getdata(t_path *path, t_env *env)
{
	DIR				*dirp;
	t_data			*curs;
	struct dirent	*dp;

	if (!(dirp = opendir(path->path)))
	{
		ft_putstr("ls: ");
		ft_putstr(path->path);
		ft_putstr(": ");
		perror("");
		env->ret = -1;
		return (-1);
	}
	curs = path->data;
	while ((dp = readdir(dirp)) != NULL)
	{
		if ((dp->d_name[0] == '.' && (env->flags & HIDE)) || dp->d_name[0] != '.')
		{
			if (path->data == NULL)
			{
				if (!(path->data = malloc(sizeof(t_data))))
					return (-1);
				curs = path->data;
			}
			else
			{
				if (!(curs->next = malloc(sizeof(t_data))))
					return (-1);
				curs = curs->next;
			}
			curs->dp = dp;
			if (stat(curs->dp->d_name, &curs->sb) == -1)
			{
				perror("error ");
//				curs->next = NULL;
				return (-1);
			}
			curs->next = NULL;
		}
	}
	return (1);
}

int					ft_fillit(t_env *env)
{
	t_path			*curs;

	curs = env->path;
	while (curs)
	{
		ft_getdata(curs, env);
		curs = curs->next;
	}
	return (1);
}

int					ft_get_opt(char **argv, int argc, t_env **env)
{
	int				i;
	int				ret;

	i = 1;
	ret = 0;
	while (i < argc && (ret = ft_checkopt(env, argv[i])) == -1)
	{
		i++;
	}
	if (ret >= 0)
		return (1000 + ret);
	return (i);
}

int			main(int argc, char **argv)
{
	t_env		*env;
	t_path		*pcurs;
	t_data		*dcurs;
	int ret;

	ret = 0;
	if (!(env = ft_init(argc, argv)))
		return (-1);
	env->ret = 0;
	ft_fillit(env);
 	pcurs = env->path;
	while (pcurs)
	{
		dcurs = pcurs->data;
		printf("path = '%s'\n",pcurs->path);
		while (dcurs)
		{
			printf("file = '%s'\n",dcurs->dp->d_name);
			printf("time = '%ld'\n",(dcurs->sb).st_mtimespec.tv_sec);
			dcurs = dcurs->next;
		}
		pcurs= pcurs->next;
	}
	ret = env->ret;
	ft_freepath(&env->path, &env);
	return(ret);
}
