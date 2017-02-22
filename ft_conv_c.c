/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 05:33:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 05:33:37 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_c(t_conv *type, t_flags flags)
{

	type->str = ft_strdup("");
	s_fill_nodot(type, flags);

	if (type->c)
	{
		// ft_putstr("CA RENTREICI");
		type->str = ft_strnew(1);
		type->str[0] = type->c;
		type->len_return = 1;
	}	
	else if (type->c == 0 && (int)ft_strlen(type->str) > 0)
	{
		ft_putstr(type->str);
		ft_putchar('\0');
		type->len_return = 1 + (int)ft_strlen(type->str);
	type->str = ft_strdup("");
		
		// type->str[0] = 0;
	}
	else
	{
		// ft_putstr("CA RENTREICI");
		ft_putchar('\0');
		type->str[0] = 0;
		type->len_return = 1;
	}
}