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
		t->len_return = ft_strlen(t->str);
	else
	{
	t->print = ft_strjoin(t->print, t->str);
	write(1, t->print, ft_strlen(t->print) + 1);
		t->len_return = ft_strlen(t->print);
		if (t->c == 0 && f.champs == 0 && f.space == 0)
			t->len_return += 1;
	t->print = ft_strdup("");
		t->str[0] = 0;
	}
}