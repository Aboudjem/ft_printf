/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_CS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 09:45:22 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_fill_zero(t_conv *type, t_flags flags)
{
	if (flags.dot > (int)ft_strlen(type->str))
		type->len_zero = flags.dot - (int)ft_strlen(type->str);
	else
		type->len_space = 0;
	type->zero = ft_strset('0', type->len_zero);
}

void	p_fill_space(t_conv *type, t_flags flags)
{
	if (flags.pad > (int)ft_strlen(type->str))
		type->len_space = flags.pad - ((int)ft_strlen(type->str) + (int)ft_strlen(type->sign));
	else
		type->len_space = 0;
	type->space = ft_strset(' ', type->len_space);
}

void	p_fill_nodot(t_conv *type, t_flags flags)
{
	int len;

	len = (int)ft_strlen(type->str) + (int)ft_strlen(type->sign);
	if (len == 0)
		len++;
	if (flags.pre == 0)
	{
		if (flags.zero == 0 && flags.pad > len)
			type->space = ft_strset(' ', flags.pad - len);
		else if (flags.zero == 1 && flags.pad > len)
			type->zero = ft_strset('0', flags.pad - len);
	}
	type->str = ft_strjoin(type->zero, type->str);
	type->str = ft_strjoin(type->sign, type->str);
	if (flags.neg == 1)
		type->str = ft_strjoin(type->str, type->space);
	else
		type->str = ft_strjoin(type->space, type->str);
}

void	ft_hexa_p(t_conv *type)
{
	int					mod;
	char				*str;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "0123456789abcdef";
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

void	conv_p(t_conv *type, t_flags flags)
{
	ft_hexa_p(type);
	type->sign = ft_strdup("0x");
	if (flags.pre == 1 && flags.pad == 0 && type->u == 0 && flags.dot == 0)
		type->str = ft_strdup(type->sign);
	else
	{
		if (flags.pre == 0)
			p_fill_nodot(type, flags);
		else
			p_join(type, flags);
	}
	type->len_return = (int)ft_strlen(type->str);
}

void	p_join(t_conv *type, t_flags flags)
{
	p_fill_space(type, flags);
	p_fill_zero(type, flags);
	type->str = ft_strjoin(type->zero, type->str);
	type->str = ft_strjoin(type->sign, type->str);
	if (flags.neg == 1)
		type->str = ft_strjoin(type->str, type->space);
	else
		type->str = ft_strjoin(type->space, type->str);
}
