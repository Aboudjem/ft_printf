/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 04:14:55 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(t_conv *t, t_flags f)
{
	if (f.neg == 1)
		f.zero = 0;
	t->str = ft_strdup("%");
	noconv_join(t, f);
	t->len_return = (int)ft_strlen(t->str);
}
