/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:57:42 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/27 00:32:00 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void len_return(t_conv *type, t_flags flags)
{
	type->len_return = 0;

	if (type->conv == 's')
		conv_s(type, flags);
	else if (type->conv == 'S')
		conv_ws(type, flags);
	else if (type->conv == 'p')
		conv_p(type, flags);
	else if (type->conv == 'd' || type->conv == 'i')// || type->conv == 'D')
		conv_d(type, flags);
	else if (type->conv == 'c')
		conv_c(type);
	else if (type->conv == 'C')
		conv_wc((unsigned long int)type->c, type);
	else if (type->conv == 'x' || type->conv == 'X')
		conv_xX(type, flags);
	else if (type->conv == 'o' || type->conv == 'O')
		conv_oO(type, flags);
	else if (type->conv == 'u' || type->conv == 'U')//|| type->conv == 'D')
		conv_u(type, flags);
	else if (type->conv == 'D')
		conv_d(type, flags);
	else if (type->conv == '%')
		conv_percent(type, flags);
	if (type->str)
	{
		ft_putstr(type->str);
		ft_strdel(&type->str);
	}
	else{
		ft_putstr(type->s);
	}
}

void	modif_length(t_flags *flags, t_conv *type)
{
	if (type->conv == 'c' && flags->l == 1)
	{
		type->conv = 'C';
		flags->l = 0;
	}
	else if (type->conv == 's' && flags->l == 1)
	{
		type->conv = 'S';
		flags->l = 0;
	}
	else if (type->conv == 'D')
	{
		type->conv = 'd';
		flags->l = 1;
		flags->hh = 0;
		flags->h = 0;
	}
	else if (type->conv == 'U')
	{
		type->conv = 'u';
		flags->l = 1;
		flags->hh = 0;
		flags->h = 0;
	}

	else if (type->conv == 'C')
	{
		type->conv = 'C';
		flags->hh = 0;
		flags->h = 0;
		// flags->l = 1;	
	}
	// 	else if (type->conv == 'O')
	// {
	// 	type->conv = 'o';
	// 	flags->hh = 0;
	// 	flags->h = 0;
	// 	flags->l = 1;
	// }

}

void  get_length(t_flags flags, t_conv *type)
{
	if (flags.h == 1)
		type->d = (short)va_arg(type->arguments,long long int);
	else if (flags.hh == 1 && flags.h == 0)
		type->d = (char)va_arg(type->arguments, long long int);
	else if (flags.ll == 1 || flags.l == 1)
		type->d = (long long)va_arg(type->arguments, long long);
	else if (flags.j == 1)
		type->d = (intmax_t)va_arg(type->arguments, long long);
	else if (flags.z == 1)
		type->d = (ssize_t)va_arg(type->arguments, long long);
	else
		type->d = (int)va_arg(type->arguments, long long int);
}

void  get_length_u(t_flags flags, t_conv *type)
{
	if (flags.h == 1)
		type->u = (unsigned short)va_arg(type->arguments,unsigned long long int);
	else if (flags.hh == 1)
		type->u = (unsigned char)va_arg(type->arguments,unsigned long long int);
	else if (flags.l == 1 || flags.ll == 1)
		type->u = (unsigned long)va_arg(type->arguments,unsigned long long int);
	else if (flags.j == 1)
		type->u = (uintmax_t)va_arg(type->arguments,unsigned long long);
	else if (flags.z == 1)
		type->u = (size_t)va_arg(type->arguments,unsigned long long);
	else
		type->u = (unsigned int)va_arg(type->arguments,unsigned long long int);
}

// void  get_length_o(t_flags flags, t_conv *type)
// {
// 	if (flags.h == 1)
// 		type->u = (unsigned short)va_arg(type->arguments,unsigned long long int);
// 	else if (flags.hh == 1)
// 		type->u = (unsigned char)va_arg(type->arguments,unsigned long long int);
// 	else if (flags.l == 1 || flags.ll == 1)
// 		type->u = (unsigned long)va_arg(type->arguments,unsigned long long int);
// 	else if (flags.j == 1)
// 		type->u = (uintmax_t)va_arg(type->arguments,unsigned long long);
// 	else if (flags.z == 1)
// 		type->u = (size_t)va_arg(type->arguments,unsigned long long);
// 	else
// 		type->u = (unsigned int)va_arg(type->arguments,unsigned long long int);
// }

t_conv which_conv(const char *s, int i, t_conv type, t_flags flags)
{
	type.count = 0;
	if (s[i] && s[i + 1])
	{
		i++;
		type.count++;
	}
	while (next_conv(s, i) == 0 && s[i + 1])
	{	
		type.count++;
		i++;
	}
	if (next_conv(s, i) == 1)
		type.count--;
	type.conv = next_conv(s, i);
	if ((int)ft_strlen(s) > 1 && (ft_isalpha(type.conv) == 1 || type.conv == '%'))
	{
		modif_length(&flags, &type);

		if (type.conv == 's')
			type.s = (char *)va_arg(type.arguments, char *);
		else if(type.conv == 'S')
			type.w = (wchar_t *)va_arg(type.arguments, wchar_t*);
		else if(type.conv == 'p')
			type.p = (void *)va_arg(type.arguments, void *);
		else if (type.conv == 'd' || type.conv == 'i')
			get_length(flags,&type);
		else if (type.conv == 'u' )
			get_length_u(flags, &type);
		else if (type.conv == 'c' || type.conv == 'C')
			type.c = (unsigned long int)va_arg(type.arguments, unsigned long int);
		else if (type.conv == 'o' || type.conv == 'x' || type.conv == 'X')
			get_length_u(flags, &type);
		else if (type.conv == 'O')
		type.u = (unsigned long int)va_arg(type.arguments, unsigned long long int);// conv_percent(&type, flags);
	else if (type.conv != '%')
		get_length_u(flags, &type);
	len_return(&type, flags);
}
else
	no_conv(s, i, &type, flags);
return (type);
}

t_flags	which_length(const char *s, int i, t_flags flags)
{
	if (s[i] == 'l' && s[i + 1] == 'l')
		flags.ll = 1;
	else if (s[i] == 'l' && s[i + 1] != 'l' && flags.ll == 0)
		flags.l = 1;
	else if (s[i] == 'j')
		flags.j = 1;
	else if (s[i] == 'z')
		flags.z = 1;
	if (s[i] == 'h' && s[i + 1] == 'h')
		flags.hh = 1;
	else if (s[i] == 'h' && s[i + 1] != 'h' && flags.hh == 0)
		flags.h = 1;
	return (flags);	
}

t_flags which_flags(const char *s, int i, t_conv type)
{
	t_flags flags;
	init_flags(&flags);  
	type.count = 0;
	i++;
	while (next_conv(s, i) == 0 && s[i] != '\0')
	{
		flags.space = (s[i] == ' ') ? 1 : flags.space;
		flags.neg = (s[i] == '-') ? 1 : flags.neg;
		flags.plus = (s[i] == '+') ? 1 : flags.plus;
		flags.hash = (s[i] == '#') ? 1 : flags.hash;
    if (s[i] >= '0' && s[i] <= '9' && flags.pre == 0)// && flags.pre == 0)
    {
    	get_padding(s, i, &flags);
    	i += flags.len_pad; 
    }
    if (s[i] == '.')
    {
    	get_precision(s, i, &flags);
    	i += flags.len_pre; 
    }
    flags = which_length(s, i, flags);
    type.count++;
    i++;
}
return (flags);
}

int ft_printf(const char *format, ...)
{
	int i = 0;
	int j = 0;
	t_conv type;
	t_flags flags;
	va_start(type.arguments, format);

	while (format[i] != '\0' && i <= (int)ft_strlen(format))
	{
		if (format[i] == '%')// && format[i + 1])
		{

			init(&type);
			flags = which_flags(format, i, type);
			type = which_conv(format, i, type, flags);
			j += type.len_return;
			i += type.count + 1;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			j++;
		}
	}
	va_end(type.arguments);
	return (j);
}
