/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 05:33:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 05:33:37 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_s(t_conv *type, t_flags flags)
{
	if (!type->s)
	{
		type->len_return = 6;
		type->str = ft_strdup("(null)");
	}
	else
	{
		type->str = ft_strdup(type->s);
		s_join(type, flags);
		type->len_return = ft_strlen(type->str);
	}
}