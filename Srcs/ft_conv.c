/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/04 06:59:36 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_nodot(t_conv *t, t_flags f)
{
	if (f.pre == 0)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->zero = ft_strset('0', f.pad - t->len_d);
	}
}

void	fill_space(t_conv *t, t_flags f)
{
	if (f.dot > f.pad && (f.pad >= t->len_d))
		t->len_space = 0;
	else if (f.pad >= f.dot)
	{
		if (f.dot > t->len_d && ((f.pad - f.dot) > 0))
			t->len_space = ((f.pad - f.dot) - ft_strlen(t->sign));
		else if (f.pad != f.dot)
		{
			if (f.dot >= (int)ft_strlen(t->nb))
				t->len_space = (f.pad - (f.dot + ft_strlen(t->sign)));
			else if (f.pad >= t->len_d)
				t->len_space = (f.pad - t->len_d);
		}
	}
	t->space = ft_strset(' ', t->len_space);
}

void	fill_zero(t_conv *t, t_flags f)
{
	if (f.dot > f.pad)
	{
		f.pad = (f.dot > f.pad) ? f.dot : f.pad;
		if (f.pad > (int)ft_strlen(t->nb))
			t->len_zero = f.pad - (ft_strlen(t->nb));
	}
	else if (f.pad >= f.dot)
	{
		if ((f.dot) > (int)ft_strlen(t->nb))
			t->len_zero = f.dot - ft_strlen(t->nb);
	}
	t->zero = ft_strset('0', t->len_zero);
}

char	*handle_zero(t_conv t, t_flags f)
{
	char *s;

	if (f.pre == 1)
	{
		t.nb = ft_strdup("");
		f = handle_d(f);
		fill_zero(&t, f);
		fill_space(&t, f);
		s = ft_strjoin(t.space, t.zero);
		s = ft_strjoin_free(&s, &t.nb, 1);
		return (ft_strjoin(s, t.sign));
	}
	return (t.nb);
}

void	join_neg(t_conv *t, t_flags f)
{
	char *s;

	if (f.negdot == 1)
	{
		if (ft_strlen(t->zero) > 0)
			t->space = ft_strset(' ',
					(ft_strlen(t->zero)) - ft_strlen(t->sign));
		else if (f.dot != 0)
			t->space = ft_strdup("");
		s = ft_strjoin(t->sign, t->nb);
		t->str = ft_strjoin_free(&s, &t->space, 1);
	}
	else if (f.neg == 1)
	{
		s = ft_strjoin(t->sign, t->zero);
		s = ft_strjoin_free(&s, &t->nb, 1);
		t->str = ft_strjoin_free(&s, &t->space, 1);
	}
}

void	join(t_conv *t, t_flags f)
{
	char *s;

	if (((t->d == 0 && f.d_used == 1) ||
				(t->u == 0 && f.u_used == 1)) && f.pre == 1)
		t->str = handle_zero(*t, f);
	else
	{
		if (f.negdot == 1 || f.neg == 1)
			join_neg(t, f);
		else
		{
			s = ft_strjoin(t->space, t->sign);
			s = ft_strjoin_free(&s, &t->zero, 1);
			t->str = ft_strjoin_free(&s, &t->nb, 1);
		}
	}
}
