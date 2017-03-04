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

void	s_fill_space(t_conv *t, t_flags f)
{
	if (f.pad > (int)ft_strlen(t->str))
		t->len_space = f.pad - (int)ft_strlen(t->str);
	else
		t->len_space = 0;
	t->space = ft_strset(' ', t->len_space);
}

int		len_c(unsigned int c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 1114112)
		return (4);
	return (0);
}

void	conv_wc(unsigned long int c, t_conv *t)
{
	how_long(c, t);
	if (c == 0)
		t->len_return = 1;
	else
		t->len_return = len_c(c);
}

void	conv_ws(t_conv *t, t_flags f)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	t->len_return = 0;
	if (!t->w || ft_wstrcmp(t->w, L"(null)") == 0)
	{
		t->len_return = 6;
		t->str = ft_strdup("(null)");
	}
	else
	{
		while (t->w[i] != '\0')
		{
			conv_wc(t->w[i], t);
			tmp = ft_strjoin_free(&tmp, &t->str, 0);
			i++;
		}
		t->str = ft_strdup(tmp);
		s_join(t, f);
		t->len_return = (int)ft_strlen(t->str);
	}
}
