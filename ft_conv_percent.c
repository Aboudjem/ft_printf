/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 08:50:41 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(t_conv *type, t_flags flags)
{
	// ft_putstr("ICI");
	if (flags.neg == 1)
		flags.zero = 0;
type->str = ft_strdup("%");
noconv_join(type, flags);
// ft_putstr("->");
// ft_putstr(type->str);
// ft_putstr("<-");

type->len_return = (int)ft_strlen(type->str);
// type->count = ;
}