/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:20:25 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 01:37:05 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(str, 0, (sizeof(char) * size + 1));
	return (str);
}
