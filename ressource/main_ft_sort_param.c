/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_sort_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:54:21 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/15 18:09:24 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int         ft_sort_cr_int(int a, int b);
int         ft_sort_ascii_str(char *s1, char *s2);
void        ft_sort_param(char ***param, int start,
  int stop, int (*cmp)(char *, char *));

int					main(int argc, char **argv)
{
	int				i;

	i = 1;
	while (i < argc)
		printf("%s\n",argv[i++]);
	printf("\nsort_parm\n\n");
	ft_sort_param(&argv,1,argc,ft_sort_ascii_str);
	i = 1;
	while (i < argc)
			printf("%s\n",argv[i++]);
}
