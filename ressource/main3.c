/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:31:39 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/19 19:49:56 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls2.h"

int       ft_ls(t_env *env, int index)
{
  env->index = index;
  printf("index %d | ft_ls\n", env->index);
  if (env->argc == 1)
  {
    ft_strcpy(env->current, ".");
    return (funtab(index +1, env));
  }
  return (funtab(index + 4, env));
}

int       funtab(int index, t_env *env)
{
  static int (*f[25])() = {ft_ls, push_stack, new_stack, add_stack,
    check_param};

  return (f[index](env, index));
}

int       main(int argc, char **argv)
{
  t_env   env;

  env.argv = argv;
  env.argc = argc;
  env.index = 0;
  env.stack = NULL;
  funtab(0,&env);
  return (funtab(0,&env));
}
