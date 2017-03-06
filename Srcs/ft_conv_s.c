/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:30:19 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/06 09:30:44 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(t_conv *t, t_flags f)
{
	if (!t->s && f.pre == 0)
	{
		t->len_return = 6;
		t->str = ft_strdup("(null)");
	}
	else if (!t->s && f.pre == 1)
	{
		if (f.zero == 0 && f.pad)
			t->str = ft_strset(' ', f.pad);
		else if (f.zero == 1 && f.pad)
			t->str = ft_strset('0', f.pad);
		t->print = ft_strjoin(t->print, t->str);
		t->len_return = ft_strlen(t->str);
		t->str = ft_strdup("");
	}
	else
	{
		t->str = ft_strdup(t->s);
		s_join(t, f);
		t->len_return = ft_strlen(t->str);
	}
}
