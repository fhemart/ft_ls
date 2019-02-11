/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:15:57 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/10 00:53:10 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(ptr, 0, (sizeof(void) * size));
	return (ptr);
}
