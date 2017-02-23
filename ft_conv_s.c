/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 05:33:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 03:19:51 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(t_conv *type, t_flags flags)
{
	if (!type->s && flags.pre == 0)
	{
		type->len_return = 6;
		type->str = ft_strdup("(null)");
	}
	else if (!type->s && flags.pre == 1)
	{
		if (flags.zero == 0 && flags.pad)
			type->str = ft_strset(' ', flags.pad);
		else if (flags.zero == 1 && flags.pad)
			type->str = ft_strset('0', flags.pad);
		ft_putstr(type->str);
		// ft_putchar('\0');
		type->len_return = ft_strlen(type->str);
		type->str = ft_strdup("");
	}
	else
	{
		type->str = ft_strdup(type->s);
		s_join(type, flags);
		type->len_return = ft_strlen(type->str);
	}
}
