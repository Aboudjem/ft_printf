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

void	s_fill_nodot(t_conv *t, t_flags f)
{
	int len;

	len = (int)ft_strlen(t->str);
	if (len == 0)
		len++;
	if (f.pre == 0 || t->conv == 'c' || t->conv == 's')
	{
		if (f.zero == 0 && f.pad > len)
			t->space = ft_strset(' ', f.pad - len);
		else if (f.zero == 1 && f.pad > len)
			t->zero = ft_strset('0', f.pad - len);
	}
	if (f.neg == 1)
	{
		if (t->zero)
			t->str = ft_strjoin(t->zero, t->str);
		if (t->space)
			t->str = ft_strjoin(t->str, t->space);
	}
	else
		s_fill_nodot2(t);
}

void	s_fill_nodot2(t_conv *t)
{
	if (t->zero)
		t->str = ft_strjoin(t->zero, t->str);
	if (t->space)
		t->str = ft_strjoin(t->space, t->str);
}

void	how_long(unsigned long int c, t_conv *t)
{
	if (c == 0)
	{
		write(1, t->print, ft_strlen(t->print) + 1);
		t->print = ft_strnew(1);
	}
	else if (MB_CUR_MAX == 1)
		one_bytes(c, t);
	else if (MB_CUR_MAX == 2)
	{
		if (c < 128 && c > 0)
			one_bytes(c, t);
		else if (c < 2048)
			two_bytes(c, t);
	}
	else if (MB_CUR_MAX == 3)
	{
		if (c < 128 && c > 0)
			one_bytes(c, t);
		else if (c < 2048)
			two_bytes(c, t);
		else if (c < 65536)
			three_bytes(c, t);
	}
	else if (MB_CUR_MAX == 4)
		how_long2(c, t);
}

void	how_long2(unsigned long int c, t_conv *t)
{
	if (c < 128 && c > 0)
		one_bytes(c, t);
	else if (c < 2048)
		two_bytes(c, t);
	else if (c < 65536)
		three_bytes(c, t);
	else if (c < 1114112)
		four_bytes(c, t);
}

void	s_join(t_conv *t, t_flags f)
{
	int i;

if (f.pre == 1 && f.dot == 0)
{	
	t->str = (f.zero == 1) ? ft_strdup("0") : ft_strdup(" ");
	f.pre = 0;
}
	if (t->conv == 'S')
		i = s_pre(t, f);
	else
		i = f.dot;
	if (f.pre == 0)
		s_fill_nodot(t, f);
	else if (f.pre == 1)
	{
		if (f.dot < (int)ft_strlen(t->str))
			t->str = ft_strsub(t->str, 0, i);
		s_fill_space(t, f);
		t->str = ft_strjoin(t->space, t->str);
	}
}