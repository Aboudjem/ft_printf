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

void	conv_s(t_conv *type)
{
	if (!type->s)
	{
		type->len_return = 6;
		type->s = ft_strdup("(null)");
	}
	else
		type->len_return = ft_strlen(type->s);
}