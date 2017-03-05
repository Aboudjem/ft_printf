/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_U.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 04:13:02 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	nb_sign_u(t_conv *t, t_flags f)
{
	t->nb = ft_litoa(t->u);
	if (t->u > 0 && f.plus == 1)
		t->sign = "";
	else if (f.space == 1)
		t->sign = "";
	t->len_d = ft_strlen(t->nb) + ft_strlen(t->sign);
}

void	conv_u(t_conv *t, t_flags f)
{
	init(t);
	nb_sign_u(t, f);
	if (f.pre == 0)
		fill_nodot(t, f);
	else
	{
		fill_zero(t, f);
		fill_space(t, f);
	}
	join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
