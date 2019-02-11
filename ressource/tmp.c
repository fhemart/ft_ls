/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhemart <fhemart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:12:52 by fhemart           #+#    #+#             */
/*   Updated: 2018/02/15 15:13:06 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static int		ft_checkopt(t_env **env, char *opt)
{
	(*env)->flags = 0;
	if (opt[0] != '-')
		return (0);
	opt++;
	while (*opt)
	{
		if (*opt == 'l' && (((*env)->flags & LIST) != LIST))
			(*env)->flags = (*env)->flags | LIST;
		else if (*opt == 'R' && (((*env)->flags & REC) != REC))
			(*env)->flags = (*env)->flags | REC;
		else if (*opt == 'a' && (((*env)->flags & HIDE) != HIDE))
			(*env)->flags = (*env)->flags | HIDE;
		else if (*opt == 'r' && (((*env)->flags & REV) != REV))
			(*env)->flags = (*env)->flags | REV;
		else if (*opt == 't' && (((*env)->flags & TIME) != TIME))
			(*env)->flags = (*env)->flags | TIME;
		else
			return (0);
		opt++;
	}
	return (1);
}
*/
