/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 03:24:43 by plisieck          #+#    #+#             */
/*   Updated: 2017/02/23 03:27:28 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_pre(t_conv *t, t_flags f)
{
	int i;

	i = 0;
	while (i + len_c(t->w[i]) <= f.dot)
		i += len_c(t->w[i]);
	return (i);
}

void	one_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(1);
	t->str[0] = c;
}

void	two_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(2);
	t->str[0] = (192 | (c >> 6));
	t->str[1] = (128 | (c & 63));
}

void	three_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(3);
	t->str[0] = (224 | (c >> 12));
	t->str[1] = (128 | ((c >> 6) & 63));
	t->str[2] = (128 | (c & 63));
}

void	four_bytes(unsigned long int c, t_conv *t)
{
	t->str = ft_strnew(4);
	t->str[0] = (240 | (c >> 18));
	t->str[1] = (128 | ((c >> 12) & 63));
	t->str[2] = (128 | ((c >> 6) & 63));
	t->str[3] = (128 | (c & 63));
}
