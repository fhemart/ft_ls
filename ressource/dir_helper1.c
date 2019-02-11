/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_helper1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 06:44:29 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/25 19:50:53 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define minor(dev) ((int)((dev) & 0xff))

#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>

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

int					ft_fileprint(const char *path)
{
	struct stat 	sb;
	struct passwd	*uid;
	struct group		*grp;

	if (stat(path, &sb) == -1)
	{
		perror("error ");
		return (-1);
	}
	uid = getpwuid(sb.st_uid);
	grp = getgrgid(sb.st_gid);
	printf("%s\n",path);
	printf("\tdevice inode: %d\n", sb.st_dev);
	printf("\tmajor: %u\n", major(sb.st_rdev));
	printf("\tminor: %u\n", minor(sb.st_rdev));
	printf("\tinode: %llu\n", sb.st_ino);
	printf("\tperms: %o\n", sb.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));
	printf("\tdirectory: %d\n", (((sb.st_mode & (S_IFDIR)) != 0) ? 1 : 0));
	printf("\tchr mode c: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFCHR)) ? 'c' : '0'));
	printf("\tchr mode b: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFBLK)) ? 'b' : '0'));
	printf("\tchr mode p: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFIFO)) ? 'p' : '0'));
	printf("\tchr mode l: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFLNK)) ? 'l' : '0'));
	printf("\tchr mode reg: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFREG)) ? '-' : '0'));
	printf("\tchr mode s: %c\n", (((sb.st_mode & (S_IFMT)) == (S_IFSOCK)) ? 's' : '0'));
	printf("\tlinks: %d\n", sb.st_nlink);
	printf("\tuid: %u\n", sb.st_uid);
	printf("\towner: %s\n", uid->pw_name);
	printf("\tgrp: %s\n", grp->gr_name);
	printf("\tguid: %u\n", sb.st_gid);
	printf("\td type: %d\n", sb.st_rdev);
	printf("\tsize: %lld\n", sb.st_size);
	printf("\tatime: %s", ctime(&sb.st_atimespec.tv_sec));
	printf("\tmtime: %s", ctime(&sb.st_mtimespec.tv_sec));
	printf("\tctime: %s", ctime(&sb.st_ctimespec.tv_sec));
	printf("\tblock: %lld\n", sb.st_blocks);
	printf("\tblksize: %d\n", sb.st_blksize);
	printf("\tflags: %u\n", sb.st_flags);
	printf("\tgen: %u\n", sb.st_gen);
	return (0);
}

int					main(void)
{
	ft_dirprint("/dev");
	ft_fileprint("/dev/disk0s1");
	return (0);
}
