/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 05:33:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 03:18:59 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_conv *t, t_flags f)
{
	char *tmp;

	tmp = ft_strnew(1);
	tmp[0] = t->c;
	t->str = ft_strdup(tmp);
	s_fill_nodot(t, f);
	if (t->c)
	{
		// t->str = ft_strnew(1);
		// t->str[0] = t->c;
		t->len_return = ft_strlen(t->str);
	}
	else if (t->c == 0 && (int)ft_strlen(t->str) > 0)
	{
		ft_putstr(t->str);
		ft_putchar('\0');
		t->len_return = 1 + (int)ft_strlen(t->str);
		t->str = ft_strdup("");
	}
	else
	{
		ft_putchar('\0');
		t->str[0] = 0;
		t->len_return = 1;
	}
}
