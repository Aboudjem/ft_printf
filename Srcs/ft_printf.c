/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:57:42 by aboudjem          #+#    #+#             */
/*   Updated: 2017/03/04 08:03:40 by aboudjem         ###   ########.fr       */
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
		t->print = ft_strjoin(t->print, t->str);
		ft_strdel(&t->str);
	}
}

void	get_conv(const char *s, int i, t_conv *t, t_flags f)
{
	if ((int)ft_strlen(s) > 1 && (ft_isalpha(t->conv) == 1 || t->conv == '%'))
	{
		modif_length(&f, t);
		if (t->conv == 's')
			t->s = (char *)va_arg(t->arguments, char *);
		else if (t->conv == 'S')
			t->w = (wchar_t *)va_arg(t->arguments, wchar_t*);
		else if (t->conv == 'p')
			t->p = (void *)va_arg(t->arguments, void *);
		else if (t->conv == 'd' || t->conv == 'i')
			get_length(&f, t);
		else if (t->conv == 'u')
			get_length_u(&f, t);
		else if (t->conv == 'c' || t->conv == 'C')
			t->c = (unsigned long int)va_arg(t->arguments, unsigned long int);
		else if (t->conv == 'o' || t->conv == 'x' || t->conv == 'X')
			get_length_u(&f, t);
		else if (t->conv == 'O')
			t->u = (unsigned long int)va_arg(t->arguments, unsigned long long int);
		else if (t->conv != '%')
			get_length_u(&f, t);
		len_return(t, f);
	}
	else
		no_conv(s, i, t, f);
}
void	which_conv(const char *s, int i, t_conv *t, t_flags f)
{
	t->count = 0;
	if (s[i] && s[i + 1])
	{
		i++;
		t->count++;
	}
	while (next_conv(s, i) == 0 && s[i + 1])
	{
		t->count++;
		i++;
	}
	if (next_conv(s, i) == 1)
		t->count--;
	t->conv = next_conv(s, i);
	get_conv(s, i, t, f);
}

void	which_flags(const char *s, int i, t_conv t, t_flags *f)
{
	// t_flags	f;

	init_flags(f);
	t.count = 0;
	i++;
	while (is_flag(s, i) == 1 && s[i] != '\0')
	{
		f->space = (s[i] == ' ') ? 1 : f->space;
		f->neg = (s[i] == '-') ? 1 : f->neg;
		f->plus = (s[i] == '+') ? 1 : f->plus;
		f->hash = (s[i] == '#') ? 1 : f->hash;
		if (s[i] >= '0' && s[i] <= '9' && f->pre == 0)
		{
			get_padding(s, i, f);
			i += f->len_pad;
		}
		if (s[i] == '.')
		{
			get_precision(s, i, f);
			i += f->len_pre;
		}
		which_length(s, i, f);
		t.count++;
		i++;
	}
}
void		printstr(const char *s, t_conv *t)
{
	int len;

	len = 0;
	while ((s[t->i] != '%' &&  s[t->i] != '\0') && s[t->i] + 1)
	{
		t->i++;
		t->j++;
		len++;
	}
	t->print = ft_strjoin(t->print, ft_strsub(s, (t->i - len), len));
}

int		ft_printf(const char *format, ...)
{
	t_conv	t;
	t_flags	f;
	init_start(&t);
	va_start(t.arguments, format);
	if (!format)
		return (0);
	while (format[t.i] != '\0' && t.i <= (int)ft_strlen(format))
	{
		if (format[t.i] == '%')
		{
			init(&t);
			which_flags(format, t.i, t, &f);
			which_conv(format, t.i, &t, f);
			t.j += t.len_return;
			t.i += t.count + 1;
		}
		else
			printstr(format, &t);
	}
	write(1, t.print, (int)ft_strlen(t.print));
	va_end(t.arguments);
	return (t.j);
}
