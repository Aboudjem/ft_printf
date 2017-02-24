/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 09:32:54 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	fill_nodot(t_conv *type, t_flags flags)
{
	if (flags.pre == 0)
	{
		if (flags.zero == 0 && flags.pad > type->len_d)
			type->space = ft_strset(' ', flags.pad - type->len_d);
		else if (flags.zero == 1 && flags.pad > type->len_d)
			type->zero = ft_strset('0', flags.pad - type->len_d);
	}
}

void	fill_space(t_conv *type, t_flags flags)
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

void	fill_zero(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad)
	{
		flags.pad = (flags.dot > flags.pad) ? flags.dot : flags.pad;
		if (flags.pad > (int)ft_strlen(type->nb))
			type->len_zero = flags.pad - (ft_strlen(type->nb));
	}
	else if (flags.pad >= flags.dot)
	{
		if ((flags.dot) > (int)ft_strlen(type->nb))
			type->len_zero = flags.dot - ft_strlen(type->nb);
	}
	type->zero = ft_strset('0', type->len_zero);
}

char	*handle_zero(t_conv type, t_flags flags)
{
	char *s;

	if (flags.pre == 1)
	{
		type.nb = ft_strdup("");
		flags = handle_d(flags);
		fill_zero(&type, flags);
		fill_space(&type, flags);
		s = ft_strjoin(type.space, type.zero);
		s = ft_strjoin_free(&s, &type.nb, 1);
		return (ft_strjoin(s, type.sign));
	}
	return (type.nb);
}
void	join_neg(t_conv *type, t_flags flags)
{
		char *s;
		
		if (flags.negdot == 1)
		{
			if (ft_strlen(type->zero) > 0)
				type->space = ft_strset(' ',
						(ft_strlen(type->zero)) - ft_strlen(type->sign));
			else if (flags.dot != 0)
				type->space = ft_strdup("");
			s = ft_strjoin(type->sign, type->nb);
			type->str = ft_strjoin_free(&s, &type->space, 1);
		}
		else if (flags.neg == 1)
		{
			s = ft_strjoin(type->sign, type->zero);
			s = ft_strjoin_free(&s, &type->nb, 1);
			type->str = ft_strjoin_free(&s, &type->space, 1);
		}
}
void	join(t_conv *type, t_flags flags)
{
	char *s;

	if (((type->d == 0 && flags.d_used == 1) ||
		(type->u == 0 && flags.u_used == 1)) && flags.pre == 1)
		type->str = handle_zero(*type, flags);
	else
	{
		if (flags.negdot == 1 || flags.neg == 1)
			join_neg(type, flags);		
		else
		{
			s = ft_strjoin(type->space, type->sign);
			s = ft_strjoin_free(&s, &type->zero, 1);
			type->str = ft_strjoin_free(&s, &type->nb, 1);
		}
	}
}
