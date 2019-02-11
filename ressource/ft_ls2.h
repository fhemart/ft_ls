/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:34:00 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/19 19:45:38 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS2_H
# define FT_LS2_H
# include <stdio.h>
# include "libft.h"
typedef struct      s_stack
{
  char              *path;
  struct s_stack    *next;
}                   t_stack;
typedef struct      s_env
{
  char              **argv;
  int               argc;
  int               index;
  char              current[4096];
  t_stack           *stack;
}                   t_env;
/* PARAM */
int       check_param(t_env *env, int index);
/* STACK */
int       push_stack(t_env *env, int index);
int       new_stack(t_env *env, int index);
int       add_stack(t_env *env, int index);
/* MAIN */
int       funtab(int index, t_env *env);
int       ft_ls(t_env *env, int index);
#endif
