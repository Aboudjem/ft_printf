/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uoxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 09:53:49 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_fill_space(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad && (flags.pad >= type->len_d))
		type->len_space = 0;
	else if (flags.pad >= flags.dot)
	{
		if (flags.dot > type->len_d && ((flags.pad - flags.dot) > 0))
			type->len_space = ((flags.pad - flags.dot) - ft_strlen(type->sign));
		else if (flags.pad == flags.dot)
			type->space = type->space;
		else
		{
			if (flags.dot >= (int)ft_strlen(type->nb))
				type->len_space = (flags.pad - (flags.dot + ft_strlen(type->sign)));
			else if (flags.pad >= type->len_d)
				type->len_space = (flags.pad - type->len_d);
		}
	}
	type->space = ft_strset(' ', type->len_space);
}

void	u_fill_zero(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad)
	{
		flags.pad = (flags.dot > flags.pad) ? flags.dot : flags.pad;
		if (flags.pad > type->len_d)
			type->len_zero = flags.pad - type->len_d;
	}
	else if (flags.pad >= flags.dot)
	{
		if ((flags.dot) > type->len_d)
			type->len_zero = flags.dot - type->len_d;
	}
	type->zero = ft_strset('0', type->len_zero);
}

char	*revert_str(char *str, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_strnew(i + 1);
	while (str[i] == '\0')
		i--;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	ft_strdel(&str);
	return (tmp);
}

void	ft_hexa(t_conv *type)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	s = "0123456789abcdef";
	nb = type->u;
	i = 0;
	if (nb == 0)
		type->nb = ft_strdup("0");
	else
	{
		type->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 16);
			type->nb[i] = s[mod];
			i++;
			nb /= 16;
		}
		type->nb = revert_str(type->nb, i);
	}
}

void	ft_octal(t_conv *type)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "01234567";
	nb = type->u;
	if (type->u == 0)
		type->nb = ft_strdup("0");
	else
	{
		type->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 8);
			type->nb[i] = s[mod];
			i++;
			nb /= 8;
		}
		type->nb = revert_str(type->nb, i);
	}
}

void	ft_hashtag(t_conv *type, t_flags flags)
{
	if (flags.hash == 1)
	{
		if (type->conv == 'x' || type->conv == 'X')
		{
			if (type->u > 0)
				type->sign = "0x";
			else
				type->sign = "";
		}
		else if (type->conv == 'o' && type->u > 0)
			type->sign = "0";
		else if (type->conv == 'o' && flags.hash == 1 && flags.pre == 1)
			type->sign = "0";
		type->len_d += (int)ft_strlen(type->sign);
	}
}

void	conv_x_bigx(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_hexa(type);
	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	if (type->conv == 'X')
		ft_strtoupper(type->str);
	type->len_return = (int)ft_strlen(type->str);
}

void	conv_o_bigo(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_octal(type);
	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);
		u_fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
}

