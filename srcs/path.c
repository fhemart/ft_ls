/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:16:48 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 18:04:08 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_path_exist(char *path, t_env *env)
{
	struct stat		sb;

	if (lstat(path, &sb) == -1)
	{
		ft_putstr("ls: ");
		if (path[0] == '\0')
			ft_putstr("fts_open");
		else
			ft_putstr(path);
		perror(" ");
		env->ret = 1;
		return (3);
	}
	return ((sb.st_mode & (S_IFDIR) || (sb.st_mode & (S_IFLNK) &&
		(!(ETIME) && !(ELIST) && !(EREC)))) ? 1 : 0);
}

char				*abs_path(char *fpath, char *path, char *tmp)
{
	size_t			len;

	len = ft_strlen(fpath);
	if (len > 1 && fpath[len - 1] == '/')
		fpath[len - 1] = '\0';
	if (ft_strcmp(fpath, "."))
	{
		ft_strcpy(tmp, fpath);
		if (ft_strcmp(fpath, "/") && ft_strcmp(fpath, "../"))
			ft_strcat(tmp, "/");
		ft_strcat(tmp, path);
	}
	else
		ft_strcpy(tmp, path);
	return (tmp);
}

int					path_check(t_env *env, t_stack *stack, t_path *path)
{
	int				is_dir;

	is_dir = ft_path_exist(stack->path, env);
	if (is_dir == 1)
	{
		if (env->start == 1)
		{
			write(1, stack->path, ft_strlen(stack->path));
			ft_putendl(":");
		}
		return (add_dir(stack->path, path, env));
	}
	else if (is_dir == 0)
		return (add_file(env, stack->path, &path->data, &path));
	else if (is_dir == -1)
		return (-1);
	else
		return (0);
}

int					is_point(char *str)
{
	if (str[ft_strlen(str) - 1] == '.')
		return (1);
	return (0);
}
