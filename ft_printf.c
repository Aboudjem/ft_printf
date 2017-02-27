/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:57:42 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/27 22:26:41 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_return(t_conv *t, t_flags f)
{
	t->len_return = 0;
	if (t->conv == 's')
		conv_s(t, f);
	else if (t->conv == 'S')
		conv_ws(t, f);
	else if (t->conv == 'p')
		conv_p(t, f);
	else if (t->conv == 'd' || t->conv == 'i')
		conv_d(t, f);
	else if (t->conv == 'c')
		conv_c(t, f);
	else if (t->conv == 'C')
		conv_wc((unsigned long int)t->c, t);
	else if (t->conv == 'x' || t->conv == 'X')
		conv_x(t, f);
	else if (t->conv == 'o' || t->conv == 'O')
		conv_o(t, f);
	else if (t->conv == 'u' || t->conv == 'U')
		conv_u(t, f);
	else if (t->conv == 'D')
		conv_d(t, f);
	else if (t->conv == '%')
		conv_percent(t, f);
	if (t->str && t->str != NULL)
	{
		ft_putstr(t->str);
		ft_strdel(&t->str);
	}
}

void	modif_length(t_flags *f, t_conv *t)
{
	if (t->conv == 'c' && f->l == 1)
	{
		t->conv = 'C';
		f->l = 0;
	}
	else if (t->conv == 's' && f->l == 1)
	{
		t->conv = 'S';
		f->l = 0;
	}
	else if (t->conv == 'D')
	{
		t->conv = 'd';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if (t->conv == 'U')
	{
		t->conv = 'u';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if (t->conv == 'O')
	{
		t->conv = 'o';
		f->l = 1;
		f->hh = 0;
		f->h = 0;
	}
	else if (t->conv == 'C')
	{
		t->conv = 'C';
		f->hh = 0;
		f->h = 0;
	}
}

void	get_length(t_flags *f, t_conv *t)
{
	f->d_used = 1;
	if (f->h == 1)
		t->d = (short)va_arg(t->arguments, long long int);
	else if (f->hh == 1 && f->h == 0)
		t->d = (char)va_arg(t->arguments, long long int);
	else if (f->ll == 1 || f->l == 1)
		t->d = (long long)va_arg(t->arguments, long long);
	else if (f->j == 1)
		t->d = (intmax_t)va_arg(t->arguments, long long);
	else if (f->z == 1)
		t->d = (ssize_t)va_arg(t->arguments, long long);
	else
		t->d = (int)va_arg(t->arguments, long long int);
}

void	get_length_u(t_flags *f, t_conv *t)
{
	f->u_used = 1;
	if (f->h == 1)
		t->u = (unsigned short)va_arg(t->arguments, unsigned long long int);
	else if (f->hh == 1)
		t->u = (unsigned char)va_arg(t->arguments, unsigned long long int);
	else if (f->l == 1 || f->ll == 1)
		t->u = (unsigned long)va_arg(t->arguments, unsigned long long int);
	else if (f->j == 1)
		t->u = (uintmax_t)va_arg(t->arguments, unsigned long long);
	else if (f->z == 1)
		t->u = (size_t)va_arg(t->arguments, unsigned long long);
	else
		t->u = (unsigned int)va_arg(t->arguments, unsigned long long int);
}

t_conv	which_conv(const char *s, int i, t_conv t, t_flags f)
{
	t.count = 0;
	if (s[i] && s[i + 1])
	{
		i++;
		t.count++;
	}
	while (next_conv(s, i) == 0 && s[i + 1])
	{
		t.count++;
		i++;
	}
	if (next_conv(s, i) == 1)
		t.count--;
	t.conv = next_conv(s, i);
	if ((int)ft_strlen(s) > 1 && (ft_isalpha(t.conv) == 1 || t.conv == '%'))
	{
		modif_length(&f, &t);
		if (t.conv == 's')
			t.s = (char *)va_arg(t.arguments, char *);
		else if (t.conv == 'S')
			t.w = (wchar_t *)va_arg(t.arguments, wchar_t*);
		else if (t.conv == 'p')
			t.p = (void *)va_arg(t.arguments, void *);
		else if (t.conv == 'd' || t.conv == 'i')
			get_length(&f, &t);
		else if (t.conv == 'u')
			get_length_u(&f, &t);
		else if (t.conv == 'c' || t.conv == 'C')
			t.c = (unsigned long int)va_arg(t.arguments, unsigned long int);
		else if (t.conv == 'o' || t.conv == 'x' || t.conv == 'X')
			get_length_u(&f, &t);
		else if (t.conv == 'O')
			t.u = (unsigned long int)va_arg(t.arguments, unsigned long long int);
		else if (t.conv != '%')
			get_length_u(&f, &t);
		len_return(&t, f);
	}
	else
		no_conv(s, i, &t, f);
	return (t);
}

t_flags	which_length(const char *s, int i, t_flags f)
{
	if (s[i] == 'l' && s[i + 1] == 'l')
		f.ll = 1;
	else if (s[i] == 'l' && s[i + 1] != 'l' && f.ll == 0)
		f.l = 1;
	else if (s[i] == 'j')
		f.j = 1;
	else if (s[i] == 'z')
		f.z = 1;
	if (s[i] == 'h' && s[i + 1] == 'h')
		f.hh = 1;
	else if (s[i] == 'h' && s[i + 1] != 'h' && f.hh == 0)
		f.h = 1;
	return (f);
}

t_flags	which_flags(const char *s, int i, t_conv t)
{
	t_flags	f;

	init_flags(&f);
	t.count = 0;
	i++;
	while (is_flag(s, i) == 1 && s[i] != '\0')
	{
		f.space = (s[i] == ' ') ? 1 : f.space;
		f.neg = (s[i] == '-') ? 1 : f.neg;
		f.plus = (s[i] == '+') ? 1 : f.plus;
		f.hash = (s[i] == '#') ? 1 : f.hash;
		if (s[i] >= '0' && s[i] <= '9' && f.pre == 0)
		{
			get_padding(s, i, &f);
			i += f.len_pad;
		}
		if (s[i] == '.')
		{
			get_precision(s, i, &f);
			i += f.len_pre;
		}
		f = which_length(s, i, f);
		t.count++;
		i++;
	}
	return (f);
}
int		printstr(const char *s, int i, int j)
{
	int len;

	len = 0;
	while((s[i] != '%' &&  s[i] != '\0') && s[i] + 1)
	{
		j++;
		i++;
		len++;
	}
ft_putstr(ft_strsub(s, (i-len), len));
return (len);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	t_conv	t;
	t_flags	f;
	int len;

	len = 0;
	i = 0;
	j = 0;
	va_start(t.arguments, format);
	while (format[i] != '\0' && i <= (int)ft_strlen(format))
	{
		if (format[i] == '%')
		{
			init(&t);
			f = which_flags(format, i, t);
			t = which_conv(format, i, t, f);
			j += t.len_return;
			i += t.count + 1;
		}
		else
		{
		//	ft_putchar(format[i]);
			//i++;
			//j++;
			len = printstr(format, i, j);
			i += len;
			j += len;
		}
	}
	va_end(t.arguments);
	return (j);
}
