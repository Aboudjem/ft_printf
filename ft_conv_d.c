/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/27 00:43:13 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


t_flags	handle_d(t_flags flags)
{
	// if (flags.pre == 1 && flags.dot == 0 &&  flags.negdot == 0) // enlever negdot au besoin
		// flags.pre = 0;
	if (flags.pre == 1 && flags.champs == 0)
		flags.pad = 0;
	if (flags.plus == 1)
		flags.space = 0;
	// if (flags.dot == 0 && flags.zero == 1)
	// 	{
	// 		ft_putstr("lolss");
	// 		flags.zero = 0;
	// 	}
	if (flags.neg == 1 && flags.zero == 1)
		flags.zero = 0;
	return(flags);
}

void	nb_sign(t_conv *type, t_flags flags)
{
type->nb = (type->d >= 0) ? ft_itoa(type->d) : ft_litoa(-type->d);
	if(type->d >= 0 && flags.plus == 1)
		type->sign = "+";
	else if(type->d < 0)
		type->sign = "-";
	else if (flags.space == 1)
		type->sign = " ";
	else
		type->sign = "";
	type->len_d = (int)ft_strlen(type->nb) + (int)ft_strlen(type->sign);
}

char *handle_zero(t_conv type, t_flags flags)
{
	char *s;
	if (flags.pre == 1)
{
if ((flags.pad == 0 || flags.champs == 0) && flags.dot == 0)
	type.nb = ft_strdup("");
else if (flags.negdot == 1 && flags.dot < 1)
	type.nb = ft_strdup(" ");
else if (flags.negdot == 1 && flags.dot > 1)
	type.nb = ft_strdup(" ");
else if (flags.negdot == 1 && flags.dot == 1)
	type.nb = ft_strdup("");
else
	{
		type.nb = ft_strdup(" ");
		flags = handle_d(flags);	
		fill_zero(&type, flags);
		fill_space(&type, flags);
		s = ft_strjoin(type.space, type.zero);
		s = ft_strjoin_free(&s, &type.nb, 1);
		return(ft_strjoin(s, type.sign));
	}
}
return(type.nb);
}

void 	conv_d(t_conv *type, t_flags flags)
{
	init(type);
	nb_sign(type, flags);
if (flags.pre == 0)
		fill_nodot(type, flags);
else
	{
		flags = handle_d(flags);	
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
}