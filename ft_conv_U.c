/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_U.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/27 00:43:13 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	nb_sign_u(t_conv *type, t_flags flags)
{
type->nb = ft_litoa(type->u);
	if(type->u > 0 && flags.plus == 1)
		type->sign = "+";
	else if (flags.space == 1)
		type->sign = " ";
	type->len_d = ft_strlen(type->nb) + ft_strlen(type->sign);
}

void	conv_u(t_conv *type, t_flags flags)
{
// char *s;
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
// return(type.str); salut
}