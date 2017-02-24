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

void	conv_x(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_hexa(type);
	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	if (type->conv == 'X')
		ft_strtoupper(type->str);
	type->len_return = (int)ft_strlen(type->str);
}

void	conv_o(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_octal(type);
	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);
		u_fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
}

