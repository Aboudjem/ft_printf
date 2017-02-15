/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_CS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 08:50:41 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa_p(t_conv *type)
{
	int mod = 0;
	int i = 0;
	unsigned long int nb;
	char *s = "0123456789abcdef";
	char *str;
	nb = (unsigned long int)type->p;
	if (nb == 0)
		type->str = ft_strdup("0");
	else
	{
	str = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 16);
			str[i] = s[mod];
			i++;
			nb /= 16;
		}
	type->str = revert_str(str, i);
	}
}

void	conv_p(t_conv *type)
{
	ft_hexa_p(type);
	char *x = ft_strdup("0x");
	// type->str = ft_strdup("");
	if (type->p > 0)
	type->str = ft_strjoin_free(&x,&type->str, 2);
	else
	type->str = ft_strjoin(x, "0");
	ft_strdel(&x);
type->len_return = (int)ft_strlen(type->str);
}