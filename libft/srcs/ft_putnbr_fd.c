/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:21:28 by fhemart           #+#    #+#             */
/*   Updated: 2017/11/12 04:57:51 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	n2;

	n2 = (long)n;
	if (n2 == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = n2 * -1;
	}
	if (n2 < 10)
		ft_putchar_fd(n2 + 48, fd);
	else
	{
		ft_putnbr_fd((int)n2 / 10, fd);
		ft_putnbr_fd((int)n2 % 10, fd);
	}
}
