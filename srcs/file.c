/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:14:08 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:12:00 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			open_err(char *path, t_env *env)
{
	ft_putstr("ls: ");
	ft_putstr(path);
	perror(" ");
	env->ret = 1;
	return (0);
}

int					add_dir(char *fpath, t_path *path, t_env *env)
{
	DIR				*dirp;

	if (!(dirp = opendir(fpath)))
		return (open_err(fpath, env));
	if (fill_path(dirp, path, env, fpath))
		return (-1);
	(void)closedir(dirp);
	return (0);
}

static void			check_len(size_t datal, t_data *data, t_path *path, char t)
{
	if (t == 1)
	{
		data->f3len = datal;
		if (datal > path->f3len)
			path->f3len = datal;
	}
	else if (t == 2)
	{
		data->f4len = datal;
		if (datal > path->f4len)
			path->f4len = datal;
	}
	else if (t == 3)
	{
		data->f5len = datal;
		if (datal > path->f5len)
			path->f5len = datal;
	}
}

int					add_file(t_env *env, char *fpath, t_data **data,
						t_path **path)
{
	struct stat		sb;
	size_t			len;

	len = 0;
	(*path)->path = fpath;
	if (lstat(fpath, &sb) == -1 && (ETIME || ELIST || EREC))
		return (0);
	if (!(*data = malloc(sizeof(t_data))))
		return (-1);
	(*path)->total += sb.st_blocks;
	(*data)->f1 = sb.st_mode;
	ft_strcpy((*data)->f1a, get_right(sb.st_mode, (*data)->f1a));
	ft_strcpy((*data)->f2, get_nblnk(sb.st_nlink, (*data)->f2));
	ft_strcpy((*data)->f3, get_uid(sb.st_uid, (*data)->f3));
	check_len(ft_strlen((*data)->f3), *data, *path, 1);
	ft_strcpy((*data)->f4, get_gid(sb.st_gid, (*data)->f4));
	check_len(ft_strlen((*data)->f4), *data, *path, 2);
	ft_strcpy((*data)->f5, get_size(sb.st_size, (*data)->f5, ((*data)->f1a)[0],
		sb.st_rdev));
	check_len(ft_strlen((*data)->f5), *data, *path, 3);
	ft_strcpy((*data)->f6a, get_time(&sb.st_mtimespec.tv_sec, (*data)->f6a));
	(*data)->f6 = sb.st_mtime;
	ft_strcpy((*data)->f7, fpath);
	(*data)->next = NULL;
	return (0);
}
