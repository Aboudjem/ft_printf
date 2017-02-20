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

void	conv_c(t_conv *type)
{
	type->str = ft_strnew(1);
	type->str[0] = type->c;

	if (type->c)
	{
		type->str = ft_strnew(1);
		type->str[0] = type->c;
		type->len_return = 1;
	}	
	else if (type->c == 0)
	{
		ft_putchar('\0');
		type->str[0] = 0;
		type->len_return = 1;

	}
}