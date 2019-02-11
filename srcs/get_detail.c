/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_detail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 15:52:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:59:14 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					get_type(int mode)
{
	char				c;

	if ((mode & S_IFMT) == S_IFREG)
		c = '-';
	else if ((mode & S_IFMT) == S_IFDIR)
		c = 'd';
	else if ((mode & S_IFMT) == S_IFBLK)
		c = 'b';
	else if ((mode & S_IFMT) == S_IFCHR)
		c = 'c';
	else if ((mode & S_IFMT) == S_IFLNK)
		c = 'l';
	else if ((mode & S_IFMT) == S_IFIFO)
		c = 'p';
	else if ((mode & S_IFMT) == S_IFSOCK)
		c = 's';
	else
		c = '?';
	return (c);
}

char					*get_right(int mode, char str[11])
{
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx", "r--", "r-x",
		"rw-", "rwx"};

	str[0] = get_type(mode);
	ft_strcpy(&str[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&str[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&str[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		str[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		str[6] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		str[9] = (mode & S_IXOTH) ? 't' : 'T';
	str[10] = '\0';
	return (str);
}

char					*get_nblnk(int nlink, char str[6])
{
	int					i;

	i = 4;
	str[5] = '\0';
	while (nlink != 0)
	{
		str[i] = (nlink % 10) + 48;
		nlink = nlink / 10;
		i--;
	}
	while (i != -1)
	{
		str[i] = ' ';
		i--;
	}
	return (str);
}

char					*get_uid(int stuid, char str[128])
{
	struct passwd		*uid;
	int					i;
	int					j;

	i = 0;
	str[127] = '\0';
	j = 126;
	if (!(uid = getpwuid(stuid)))
	{
		while (stuid != 0)
		{
			str[j] = (stuid % 10) + 48;
			stuid = stuid / 10;
			j--;
		}
		while (j < 128)
			str[i++] = str[++j];
		str[i] = '\0';
	}
	else
	{
		ft_strcpy(str, uid->pw_name);
	}
	return (str);
}

char					*get_gid(int stgrp, char str[128])
{
	struct group		*grp;
	int					i;
	int					j;

	i = 0;
	str[127] = '\0';
	j = 126;
	if (!(grp = getgrgid(stgrp)))
	{
		while (stgrp != 0)
		{
			str[j] = (stgrp % 10) + 48;
			stgrp = stgrp / 10;
			j--;
		}
		while (j < 128)
			str[i++] = str[++j];
		str[i] = '\0';
	}
	else
	{
		ft_strcpy(str, grp->gr_name);
	}
	return (str);
}
