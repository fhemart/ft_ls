/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:21:32 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/11 20:48:31 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
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
typedef struct		s_data
{
	char			*name;
	int				timestamp;
	struct dirent	*dp;
	struct stat	sb;
	struct s_data	*next;
}					t_data;
typedef struct		s_path
{
	char			*path;
	struct s_data	*data;
	struct s_path	*next;
}					t_path;
typedef struct		s_env
{
	t_flags			flags;
	int				ret;
	struct s_path	*path;
}					t_env;
int					ft_get_opt(char **argv, int argc, t_env **env);
int					ft_checkopt(t_env **env, char *opt);
t_env				*ft_freepath(t_path	**path, t_env **env);
t_env				*ft_addpath(t_env **env, char *str);
void				usage(t_env **env, char c);
t_env				*ft_init(int argc, char **argv);
#endif
