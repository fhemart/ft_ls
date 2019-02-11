/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:45:43 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/24 23:15:26 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_char.h"

t_str			*ft_smax_init(const char *str)
{
	t_str		*smax;

	if (!(smax = malloc(sizeof(t_str))))
		return (NULL);
	smax->next = NULL;
	ft_bzero((void *)smax->str, S_MAX + 1);
	smax->len = 0;
	if (str != NULL)
	{
		if (ft_smax_add(smax, str) == -1)
		{
			ft_smax_close(&smax);
			return (NULL);
		}
	}
	return (smax);
}

size_t			ft_smax_len(t_str *smax)
{
	size_t		len;

	len = 0;
	while (smax)
	{
		len = len + smax->len;
		smax = smax->next;
	}
	return (len);
}

void			ft_smax_wclose(t_str **smax)
{
	t_str		*tmp;
	t_str		*curs;

	curs = (*smax)->next;
	write(1, (*smax)->str, (*smax)->len);
	while (curs)
	{
		tmp = curs;
		write(1, curs->str, curs->len);
		curs = curs->next;
		free(tmp);
		tmp = NULL;
	}
	ft_bzero((void *)(*smax)->str, S_MAX + 1);
	smax->len = 0;
}

void			ft_smax_close(t_str **smax)
{
	t_str		*tmp;

	while (*smax)
	{
		tmp = (*smax);
		(*smax) = (*smax)->next;
		free(tmp);
		tmp = NULL;
	}
}

t_str			*ft_smax_select(t_str *smax)
{
	t_str		*curs;

	curs = smax;
	while (curs->next)
		curs = curs->next;
	return (curs);
}

int			ft_smax_split(t_str *smax, const char *str, size_t strlen)
{
	size_t		i;
	size_t		limit;

	i = 0;
	if (strlen > S_MAX)
		limit = S_MAX;
	else
	{
		limit = S_MAX - (strlen + smax->len);
		printf("limit :%zu\n",limit);
	}
	while (smax->len + i < limit)
	{
		smax->str[smax->len + i] = str[i];
//		printf("i :%zu | c :%c |smax :%zu\n",i, str[i], smax->len +i);
		i++;
	}
//	printf("str =%s | %p\n",smax->str, &smax->str);
	smax->len = smax->len + i;
	if (!(smax->next = ft_smax_init(str + i)))
		return (-1);
	return (1);
}

int			ft_smax_add(t_str *smax, const char *str)
{
	size_t		strlen;
	t_str		*curs;

	curs = ft_smax_select(smax);
	strlen = ft_strlen(str);
//	printf("smax len :%zu | strlen :%zu\n",curs->len, strlen);
	if ((strlen + curs->len) <= S_MAX - curs->len)
	{
//		printf("strcpy =%s | %p\n",curs->str, &curs->str);
		ft_strcpy(curs->str + curs->len, str);
		curs->len = curs->len + strlen;
	}
	else
		return (ft_smax_split(curs, str, strlen));
	return (1);
}

int			main(void)
{
	t_str		*test;
	t_str		*curs;

	test = ft_smax_init("try the best\n");
	curs = test;
//	while (curs)
//	{
//		printf("%s",curs->str);
//		curs = curs->next;
//	}
//	curs = test;
	ft_smax_add(test, "fuck one duck and try to fly");
//	ft_smax_close(&test);
	printf("len =%zu\n",ft_smax_len(test));
	while (test)
	{
		printf("%s",test->str);
		test = test->next;
	}
}
