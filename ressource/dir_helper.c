/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 06:44:29 by fhemart           #+#    #+#             */
/*   Updated: 2018/01/30 03:50:10 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include "libft/libft.h"

char				*cconvertbase10(int nb, int base)
{
	char			*str;
	char			*tmp;
	char			*ptr;
	char			*baserep;

	baserep = "0123456789abcdef";
	if ((nb > 255 && nb < 65534) || nb < 0)
		nb = (unsigned char)nb;
	tmp = ft_strnew(50);
	ptr = &tmp[49];
	while (nb != 0)
	{
		*--ptr = baserep[nb % base];
		nb = nb / base;
	}
	if (ft_strlen(ptr) > 0)
		str = ft_strdup(ptr);
	else
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	free(tmp);
	return (str);
}

int					ft_dirprint(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(path);
	if (dirp == NULL)
	{
		perror("error ");
		return (-1);
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		printf("%s\n",dp->d_name);
	}
	(void)closedir(dirp);
	return (1);
}
char				*major(char *dest, int st_rdev)
{
	int			len;
	int			i;
	char		str[4];

	st_rdev = st_rdev >> 24;
	i = 2;
	ft_memset(str,' ', 4);
	while (st_rdev > 9)
	{
		str[i] = (st_rdev % 10) + 48;
		st_rdev = st_rdev / 10;
		i--;
	}
	str[i] = st_rdev + 48;
	len = ft_strlen(dest);
	ft_strcpy(dest + len, str);
	return (dest);
}

int				minor(char *dest,int st_rdev)
{
	printf("\tstr :%s\n",dest);
	return (st_rdev & 0xff);
}

int					ft_fileprint(const char *path)
{
	struct stat 	sb;
	int				r_rdev;
	char			str[500];

	ft_bzero((void *)str,500);
	if (stat(path, &sb) == -1)
	{
		perror("error ");
		return (-1);
	}
	printf("%s\n",path);
	printf("\tdevice inode: %d\n", sb.st_dev);
	printf("\tinode: %llu\n", sb.st_ino);
	printf("\tperms: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	printf("\tlinks: %d\n", sb.st_nlink);
	printf("\tuid: %u\n", sb.st_uid);
	printf("\tguid: %u\n", sb.st_gid);
	printf("\td type: %d\n", sb.st_rdev);
	if (S_ISCHR(sb.st_mode) || S_ISBLK(sb.st_mode))
	{
		printf("\tmajor block: %s\n", major(str,sb.st_rdev));
		printf("\tminor block: %d\n", minor(str,sb.st_rdev));
	}
	else
	{
		printf("\tsize: %lld\n", sb.st_size);
	}
	printf("\tatime: %s", ctime(&sb.st_atimespec.tv_sec));
	printf("\tmtime: %s", ctime(&sb.st_mtimespec.tv_sec));
	printf("\tctime: %s", ctime(&sb.st_ctimespec.tv_sec));
	printf("\tblock: %lld\n", sb.st_blocks);
	printf("\tblksize: %d\n", sb.st_blksize);
	printf("\tflags: %u\n", sb.st_flags);
	printf("\tgen: %u\n", sb.st_gen);
	r_rdev = sb.st_rdev;
	printf("\tsizeof rdev: %zu\n",sizeof(r_rdev));
	printf("\tbinari rdev major: %s\n",cconvertbase10((r_rdev >> 24),2));
	printf("\tbinari rdev minor: %s\n",cconvertbase10((r_rdev & 0xff),2));
	return (0);
//	00000100 00000000 00000000 01111111
}

int					main(void)
{
	ft_dirprint("/dev");
	ft_fileprint("/dev/zero");
	return (0);
}
