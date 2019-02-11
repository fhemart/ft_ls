/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:54:22 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 17:48:47 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					fill_path(DIR *dirp, t_path *path, t_env *env, char *fpath)
{
	struct dirent	*dp;
	char			tmp[4096];
	t_data			*curs;

	while ((dp = readdir(dirp)) != NULL)
	{
		if ((DNAME[0] == '.' && (env->flags & HIDE)) || DNAME[0] != '.')
		{
			if (path->data == NULL)
			{
				if (add_file(env, abs_path(fpath, DNAME, tmp),
					&path->data, &path) == -1)
					return (-1);
				curs = path->data;
			}
			else
			{
				if (add_file(env, abs_path(fpath, DNAME, tmp),
					&curs->next, &path) == -1)
					return (-1);
				curs = curs->next;
			}
		}
	}
	return (0);
}

char				*get_size(int stsize, char str[20], char type, int rdev)
{
	int				i;
	int				j;

	i = 0;
	str[19] = '\0';
	j = 18;
	if (type == 'c' || type == 'b')
	{
		ft_strcpy(str, get_maj(major(rdev), str));
		ft_strcat(str, ",");
		ft_strcpy(str, get_min(minor(rdev), str));
		return (str);
	}
	if (stsize == 0)
		str[j--] = '0';
	while (stsize != 0)
	{
		str[j] = (stsize % 10) + 48;
		stsize = stsize / 10;
		j--;
	}
	while (j < 19)
		str[i++] = str[++j];
	str[i] = '\0';
	return (str);
}

char				*get_total(int total)
{
	static char		str[20];
	int				i;
	int				j;

	i = 0;
	str[19] = '\0';
	j = 18;
	if (total == 0)
		str[j--] = '0';
	while (total != 0)
	{
		str[j] = (total % 10) + 48;
		total = total / 10;
		j--;
	}
	while (j < 19)
		str[i++] = str[++j];
	str[i] = '\0';
	return (str);
}

char				*get_time(long int *mtime, char str[24])
{
	long int		*ttime;
	char			*tstr;

	ttime = NULL;
	tstr = ctime(mtime);
	ft_strcpy(str, tstr + 4);
	if (time(ttime) - *mtime > 31536000)
	{
		ft_strcpy(str + 7, tstr + 20);
		str[11] = '\0';
	}
	else
	{
		str[12] = '\0';
	}
	return (str);
}

char				*get_link(char path[4096])
{
	char			tmp[4096];
	int				pos;

	pos = readlink((const char *)path, (char*)tmp, 4096);
	tmp[pos] = '\0';
	ft_strcat(path, " -> ");
	ft_strcat(path, tmp);
	return (path);
}
