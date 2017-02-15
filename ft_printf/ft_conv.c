/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:39:58 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/27 00:43:13 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_padding(const char *s, int i, t_flags *flags)
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
	flags->pad = ft_atoi(s+i);
   	while (ft_isdigit(s[i]) == 1 )
	{
		j++;
		i++;
	}
    flags->len_pad = j;
 }

void	get_precision(const char *s, int i, t_flags *flags)
{
	int j;
	j = 0;
    flags->pre = (s[i] == '.') ? 1 : flags->pre;
	i++;
	flags->negdot = (s[i] == '-') ? 1 : flags->negdot;
	// i++;
	flags->dot = ft_atoi(s+i);
	if(next_conv(s, i++) == 0)
		j++;
	flags->len_pre = j + flags->pre + flags->negdot;
}

char next_conv(const char *s, int i)
{
    int j = 0;
    char *conv = "sSpdDioOuUxXcC";
    while (conv[j] != '\0')
    {
	if (s[i] != conv[j])
	    j++;
	else
	    return (conv[j]);
    }
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
}

void	fill_nodot(t_conv *type, t_flags flags)
{
	if (flags.pre == 0)
	{
	if (flags.zero == 0 && flags.pad > type->len_d)
			type->space = ft_strset(' ', flags.pad - type->len_d);
	else if (flags.zero == 1 && flags.pad > type->len_d)
			type->zero = ft_strset('0', flags.pad - type->len_d);
	}
}

void	fill_space(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad && (flags.pad >= type->len_d))
	type->len_space = 0;//flags.pad - type->len_d;
	else if (flags.pad >= flags.dot)
	{
		if (flags.dot > type->len_d && ((flags.pad - flags.dot) > 0) )
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

void	fill_zero(t_conv *type, t_flags flags)
{
	if (flags.dot > flags.pad)
	{
	flags.pad = (flags.dot > flags.pad) ? flags.dot : flags.pad;
	if (flags.pad > (int)ft_strlen(type->nb))
		type->len_zero = flags.pad - (ft_strlen(type->nb));
	}	
	else if (flags.pad >= flags.dot)
	{
		if ((flags.dot) > (int)ft_strlen(type->nb))
				type->len_zero = flags.dot - ft_strlen(type->nb);
	}
	type->zero = ft_strset('0', type->len_zero);
}

void join(t_conv *type, t_flags flags)
{
	char *s;
// ft_putnbr(type->d);
// ft_putendl("----");
// ft_putnbr(type->u);
	if ((type->d == 0 || type->u == 0) && flags.pre == 1 && (flags.negdot == 1 || flags.dot == 0)) //(flags.negdot == 1 || flags.dot == 0))//flagschamps =1
		{
	// ft_putstr("ici");
			type->str = handle_zero(*type, flags);
		}
	else if (flags.negdot == 1)
	{
		if (ft_strlen(type->zero) > 0)
				type->space = ft_strset(' ', (ft_strlen(type->zero)) - ft_strlen(type->sign));
		else if (flags.dot != 0)
				type->space = ft_strdup("");
		s = ft_strjoin(type->sign, type->nb);
		type->str = ft_strjoin_free(&s, &type->space, 1);
	}
	else if (flags.neg == 1) 
	{
		
		s = ft_strjoin(type->sign, type->zero);
		s = ft_strjoin_free(&s, &type->nb, 1);
		type->str = ft_strjoin_free(&s, &type->space, 1);
	}
	else
	{
s = ft_strjoin(type->space, type->sign);
s = ft_strjoin_free(&s, &type->zero, 1);
type->str = ft_strjoin_free(&s, &type->nb, 1);
	}
 if (ft_strlen(type->zero) > 0)
 	ft_strdel(&type->zero);
 if (ft_strlen(type->space) > 0)
 	ft_strdel(&type->space);
 // if (ft_strlen(type->nb) > 0)
 // 	ft_strdel(&type->nb);
 // ft_putendl("---");
 // ft_putstr(type->str);
 // ft_putendl("---");
}