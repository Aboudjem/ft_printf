/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_U.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 04:13:02 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_fill_space(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad && (flags.pad >= type->len_d))
		type->len_space = 0;
	else if (flags.pad >= flags.dot)
	{
		if (flags.dot > type->len_d && ((flags.pad - flags.dot) > 0))
			type->len_space = ((flags.pad - flags.dot) - ft_strlen(type->sign));
		else if (flags.pad == flags.dot)
			type->space = type->space;
		else
		{
			if (flags.dot >= (int)ft_strlen(type->nb))
				type->len_space = (flags.pad - (flags.dot + ft_strlen(type->sign)));
			else if (flags.pad >= type->len_d)
				type->len_space = (flags.pad - type->len_d);
		}
	}
	type->space = ft_strset(' ', type->len_space);
}

void	u_fill_zero(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad)
	{
		flags.pad = (flags.dot > flags.pad) ? flags.dot : flags.pad;
		if (flags.pad > type->len_d)
			type->len_zero = flags.pad - type->len_d;
	}
	else if (flags.pad >= flags.dot)
	{
		if ((flags.dot) > type->len_d)
			type->len_zero = flags.dot - type->len_d;
	}
	type->zero = ft_strset('0', type->len_zero);
}

void	nb_sign_u(t_conv *type, t_flags flags)
{
	type->nb = ft_litoa(type->u);
	if (type->u > 0 && flags.plus == 1)
		type->sign = "";
	else if (flags.space == 1)
		type->sign = "";
	type->len_d = ft_strlen(type->nb) + ft_strlen(type->sign);
}

void	conv_u(t_conv *type, t_flags flags)
{
	init(type);
	nb_sign_u(type, flags);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
}
