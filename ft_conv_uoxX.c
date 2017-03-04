/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uoxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 09:53:49 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_fill_nodot(t_conv *t, t_flags f)
{
	if (f.pre == 0 && f.neg == 0)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->zero = ft_strset('0', f.pad - t->len_d);
	}
	else if (f.pre == 0 && f.neg == 1)
	{
		if (f.zero == 0 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
		else if (f.zero == 1 && f.pad > t->len_d)
			t->space = ft_strset(' ', f.pad - t->len_d);
	
	}
}


void	conv_x(t_conv *t, t_flags f)
{
	init(t);
	ft_hashtag(t, f);
	ft_hexa(t);
	t->len_d += ft_strlen(t->nb);
	if (f.pre == 0)
		x_fill_nodot(t, f);
	else
	{
		f = handle_d(f);
		fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	if (t->conv == 'X')
		ft_strtoupper(t->str);
	t->len_return = (int)ft_strlen(t->str);
}

void	conv_o(t_conv *t, t_flags f)
{
	init(t);
	ft_hashtag(t, f);
	ft_octal(t);
	t->len_d += ft_strlen(t->nb);
	if (f.pre == 0)
		x_fill_nodot(t, f);
	else
	{
		f = handle_d(f);
		u_fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}

