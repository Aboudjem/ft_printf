/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_CS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/04 07:48:56 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_fill_zero(t_conv *t, t_flags f)
{
	if (f.dot > (int)ft_strlen(t->str))
		t->len_zero = f.dot - (int)ft_strlen(t->str);
	else
		t->len_space = 0;
	t->zero = ft_strset('0', t->len_zero);
}

void	p_fill_space(t_conv *t, t_flags f)
{
	int len;

	len = ((int)ft_strlen(t->str) + (int)ft_strlen(t->sign));
	if (f.pad > (int)ft_strlen(t->str))
		t->len_space = f.pad - len;
	else
		t->len_space = 0;
	t->space = ft_strset(' ', t->len_space);
}

void	p_fill_nodot(t_conv *t, t_flags f)
{
	int len;

	len = (int)ft_strlen(t->str) + (int)ft_strlen(t->sign);
	if (len == 0)
		len++;
	if (f.pre == 0)
	{
		if (f.zero == 0 && f.pad > len)
			t->space = ft_strset(' ', f.pad - len);
		else if (f.zero == 1 && f.pad > len)
			t->zero = ft_strset('0', f.pad - len);
	}
	t->str = ft_strjoin(t->zero, t->str);
	t->str = ft_strjoin(t->sign, t->str);
	if (f.neg == 1)
		t->str = ft_strjoin(t->str, t->space);
	else
		t->str = ft_strjoin(t->space, t->str);
}

void	ft_hexa_p(t_conv *t)
{
	int					mod;
	char				*str;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "0123456789abcdef";
	nb = (unsigned long int)t->p;
	if (nb == 0)
		t->str = ft_strdup("0");
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
		t->str = revert_str(str, i);
	}
}

void	conv_p(t_conv *t, t_flags f)
{
	ft_hexa_p(t);
	if (t->p == 0 && (f.pre == 1 && f.dot == 0))
		t->str = ft_strdup("");
	t->sign = ft_strdup("0x");
	if (f.pre == 1 && f.pad == 0 && t->u == 0 && f.dot == 0)
		t->str = ft_strdup(t->sign);
	else
	{
		if (f.pre == 0)
			p_fill_nodot(t, f);
		else
			p_join(t, f);
	}
	t->len_return = (int)ft_strlen(t->str);
}

void	p_join(t_conv *t, t_flags f)
{
	p_fill_space(t, f);
	p_fill_zero(t, f);
	t->str = ft_strjoin(t->zero, t->str);
	t->str = ft_strjoin(t->sign, t->str);
	if (f.neg == 1)
		t->str = ft_strjoin(t->str, t->space);
	else
		t->str = ft_strjoin(t->space, t->str);
}
