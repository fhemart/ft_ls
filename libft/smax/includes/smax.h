/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smax.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:37:15 by fhemart           #+#    #+#             */
/*   Updated: 2018/03/02 20:49:33 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMAX_H
# define SMAX_H
# define S_MAX 4096
# include "../../libft/includes/libft.h"

typedef struct		s_str
{
	char			str[S_MAX + 1];
	size_t			len;
	struct s_str	*next;
}					t_str;
t_str				*ft_smax_init(const char *str);
t_str				*ft_smax_select(t_str *smax);
void				ft_smax_close(t_str **smax);
int					ft_smax_add(t_str *smax, const char *str);
int					ft_smax_split(t_str *smax, const char *str, size_t strlen);
size_t				ft_smax_len(t_str *smax);
void				ft_smax_wclose(t_str **smax);
#endif
