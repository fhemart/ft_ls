/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:28:59 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/03 21:45:13 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "../libft/includes/libft.h"
# include "../libft/smax/includes/smax.h"
# define DNAME dp->d_name
# define ETIME env->flags & TIME
# define ELIST env->flags & LIST
# define EREC env->flags & REC
# define MAX_FLAGS 5
# define FLAG_L 'l'
# define FLAG_GR 'R'
# define FLAG_A 'a'
# define FLAG_R 'r'
# define FLAG_T 't'
# define ALL_FLAGS FLAG_L, FLAG_GR, FLAG_A, FLAG_R, FLAG_T

typedef enum		e_flags
{
	NOP = 0,
	LIST = 1,
	REC = 2,
	HIDE = 4,
	REV = 8,
	TIME = 16
}					t_flags;
typedef struct		s_stack
{
	char			path[4096];
	struct s_stack	*next;
}					t_stack;
typedef struct		s_data
{
	struct s_data	*next;
	int				f1;
	char			f1a[11];
	char			f2[6];
	char			f3[128];
	char			f4[128];
	char			f5[20];
	long int		f6;
	char			f6a[24];
	char			f7[4096];
	size_t			f3len;
	size_t			f4len;
	size_t			f5len;
}					t_data;
typedef struct		s_path
{
	char			*path;
	struct s_data	*data;
	size_t			f3len;
	size_t			f4len;
	size_t			f5len;
	int				total;
}					t_path;
typedef struct		s_env
{
	t_stack			*stack;
	t_flags			flags;
	t_str			*smax;
	char			start;
	char			space[20];
	int				ret;
}					t_env;
/*
**		STACK
*/
int					push_stack(t_stack **stack, char *path, int parent);
void				join_stack(t_stack **fstack, t_stack **bstack);
/*
**		OPT
*/
int					opt_engine(t_env *env, int argc, char **argv);
/*
**		FILE
*/
int					add_dir(char *fpath, t_path *path, t_env *env);
int					add_file(t_env *env, char *fpath, t_data **data,
						t_path **path);
/*
**		FILL_PATH
*/
int					fill_path(DIR *dirp, t_path *path, t_env *env, char *fpath);
char				*get_size(int stsize, char str[20], char type, int rdev);
char				*get_time(long int *mtime, char str[24]);
char				*get_link(char path[4096]);
char				*get_total(int total);
/*
**		PATH
*/
int					ft_path_exist(char *path, t_env *env);
int					path_check(t_env *env, t_stack *stack, t_path *path);
char				*abs_path(char *fpath, char *path, char *tmp);
int					is_point(char *str);
/*
**		GET_DETAIL
*/
char				get_type(int mode);
char				*get_right(int mode, char str[11]);
char				*get_nblnk(int nlink, char str[6]);
char				*get_uid(int stuid, char str[128]);
char				*get_gid(int stgrp, char str[128]);
/*
**		GET_DETAIL2
*/
char				*get_maj(int stmajor, char str[20]);
char				*get_min(int stmajor, char str[20]);
/*
**		FINAL_LOOP
*/
int					print_path(t_env *env);
/*
**		LIBFT
*/
void				ft_lstrev1(t_data **begin_list);
int					ft_sort_cr_int(int a, int b);
int					ft_sort_dr_int(int a, int b, char *s1, char *s2);
int					ft_sort_ascii_str(int a, int b, char *s1, char *s2);
void				ft_sort_param(char ***param, int start,
						int stop, int (*cmp)(int, int, char *, char *));
t_data				*ft_sort_list(t_data *lst, int (*cmp)());
void				swap(void **elem, void **elem2);
t_data				*sort_lst(t_data **tab, size_t tab_size, int (*cmp)());
t_data				*set_next(t_data **tab, size_t tab_size);
#endif
