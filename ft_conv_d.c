/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 03:17:53 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	handle_d(t_flags flags)
{
	if (flags.pre == 1 && flags.champs == 0)
		flags.pad = 0;
	if (flags.plus == 1)
		flags.space = 0;
	if (flags.neg == 1 && flags.zero == 1)
		flags.zero = 0;
	return (flags);
}

void	nb_sign(t_conv *type, t_flags flags)
{
	type->nb = (type->d >= 0) ? ft_itoa(type->d) : ft_litoa(-type->d);
	if (type->d >= 0 && flags.plus == 1)
		type->sign = "+";
	else if (type->d < 0)
		type->sign = "-";
	else if (flags.space == 1)
		type->sign = " ";
	else
		type->sign = "";
	type->len_d = (int)ft_strlen(type->nb) + (int)ft_strlen(type->sign);
}

void	conv_d(t_conv *type, t_flags flags)
{
	init(type);
	flags = handle_d(flags);
	nb_sign(type, flags);
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
