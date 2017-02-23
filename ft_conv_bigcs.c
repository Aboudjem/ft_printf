/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_CS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/23 03:44:58 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_fill_nodot(t_conv *type, t_flags flags)
{
	int len;

	len = (int)ft_strlen(type->str);
	if (len == 0)
		len++;
	if (flags.pre == 0 || type->conv == 'c' || type->conv == 's')
	{
		if (flags.zero == 0 && flags.pad > len)
			type->space = ft_strset(' ', flags.pad - len);
		else if (flags.zero == 1 && flags.pad > len)
			type->zero = ft_strset('0', flags.pad - len);
	}
	if (flags.neg == 1)
	{
		if (type->zero)
			type->str = ft_strjoin(type->zero, type->str);
		if (type->space)
			type->str = ft_strjoin(type->str, type->space);
	}
	else
		s_fill_nodot2(type);
}

void	s_fill_nodot2(t_conv *type)
{
	if (type->zero)
		type->str = ft_strjoin(type->zero, type->str);
	if (type->space)
		type->str = ft_strjoin(type->space, type->str);
}

void	how_long(unsigned long int c, t_conv *type)
{
	if (MB_CUR_MAX == 1)
		one_bytes(c, type);
	else if (MB_CUR_MAX == 2)
	{
		if (c < 128 && c > 0)
			one_bytes(c, type);
		else if (c < 2048)
			two_bytes(c, type);
	}
	else if (MB_CUR_MAX == 3)
	{
		if (c < 128 && c > 0)
			one_bytes(c, type);
		else if (c < 2048)
			two_bytes(c, type);
		else if (c < 65536)
			three_bytes(c, type);
	}
	else if (MB_CUR_MAX == 4)
		how_long2(c, type);
}

void	how_long2(unsigned long int c, t_conv *type)
{
	if (c < 128 && c > 0)
		one_bytes(c, type);
	else if (c < 2048)
		two_bytes(c, type);
	else if (c < 65536)
		three_bytes(c, type);
	else if (c < 1114112)
		four_bytes(c, type);
}

void	s_join(t_conv *type, t_flags flags)
{
	int i;

if (flags.pre == 1 && flags.dot == 0)
{	
	type->str = (flags.zero == 1) ? ft_strdup("0") : ft_strdup(" ");
	flags.pre = 0;
}
	if (type->conv == 'S')
		i = s_pre(type, flags);
	else
		i = flags.dot;
	if (flags.pre == 0)
		s_fill_nodot(type, flags);
	else if (flags.pre == 1)
	{
		if (flags.dot < (int)ft_strlen(type->str))
			type->str = ft_strsub(type->str, 0, i);
		s_fill_space(type, flags);
		type->str = ft_strjoin(type->space, type->str);
	}
}
