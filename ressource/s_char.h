/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_char.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:37:15 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/24 23:15:57 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CHAR_H
# define S_CHAR_H
# define S_MAX 500
# include "libft.h"

typedef struct		s_str
{
	char		str[S_MAX + 1];
	size_t		len;
	struct s_str	*next;
}			t_str;
t_str			*ft_smax_init(const char *str);
t_str			*ft_smax_select(t_str *smax);
void			ft_smax_close(t_str **smax);
int			ft_smax_add(t_str *smax, const char *str);
int			ft_smax_split(t_str *smax, const char *str, size_t strlen);
size_t			ft_smax_len(t_str *smax);
void			ft_smax_wclose(t_str **smax);
# endif
