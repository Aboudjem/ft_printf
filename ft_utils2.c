/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_bigcs3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 03:28:15 by plisieck          #+#    #+#             */
/*   Updated: 2017/02/23 03:38:21 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_padding(const char *s, int i, t_flags *flags)
{
	int j;

	j = 0;
	flags->zero = (s[i] == '0') ? 1 : flags->zero;
	flags->champs = 1;
	while (ft_isdigit(s[i]) == 0)
	{
		j++;
		i++;
	}
	flags->zero = (s[i] == '0') ? 1 : flags->zero;
	flags->pad = ft_atoi(s + i);
	while (ft_isdigit(s[i]) == 1)
	{
		j++;
		i++;
	}
	flags->neg = (s[i] == '-') ? 1 : flags->neg;
	flags->len_pad = j;
}

void	get_precision(const char *s, int i, t_flags *flags)
{
	int j;

	j = 0;
	flags->pre = (s[i] == '.') ? 1 : flags->pre;
	i++;
	flags->negdot = (s[i] == '-') ? 1 : flags->negdot;
	flags->dot = ft_atoi(s + i);
	if (next_conv(s, i++) == 0)
		j++;
	flags->len_pre = j + flags->pre + flags->negdot;
}

int		is_flag(const char *s, int i)
{
	int		j;
	char	*flag;

	j = 0;
	flag = " -#+.0123456789lhjz";
	while (flag[j] != '\0')
	{
		if (s[i] != flag[j])
			j++;
		else
			return (1);
	}
	return (0);
}

char	next_conv(const char *s, int i)
{
	int		j;
	char	*conv;

	j = 0;
	conv = "sSpdDioOuUxXcC%";
	while (conv[j] != '\0')
	{
		if (s[i] == conv[j])
			return (conv[j]);
		j++;
	}
	if (is_flag(s, i) == 0)
		return (1);
	return (0);
}

void	init(t_conv *type)
{
	type->len_d = 0;
	type->len_space = 0;
	type->len_zero = 0;
	type->sign = "";
	type->space = "";
	type->zero = "";
	type->str = NULL;
	type->len_return = 0;
}