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

void	s_fill_space(t_conv *type, t_flags flags)
{
	if (flags.pad > (int)ft_strlen(type->str))
		type->len_space = flags.pad - (int)ft_strlen(type->str);
	else
		type->len_space = 0;
	type->space = ft_strset(' ', type->len_space);
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

void	conv_wc(unsigned long int c, t_conv *type)
{
	how_long(c, type);
	if (c == 0)
	{
		ft_putchar('\0');
		ft_bzero(type->str, 1);
		type->len_return = 1;
	}
	else
		type->len_return = len_c(c);
}

void	conv_ws(t_conv *type, t_flags flags)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup("");
	type->len_return = 0;
	if (!type->w || ft_wstrcmp(type->w, L"(null)") == 0)
	{
		type->len_return = 6;
		type->str = ft_strdup("(null)");
	}
	else
	{
		while (type->w[i] != '\0')
		{
			conv_wc(type->w[i], type);
			tmp = ft_strjoin_free(&tmp, &type->str, 0);
			i++;
		}
		type->str = ft_strdup(tmp);
		s_join(type, flags);
		type->len_return = (int)ft_strlen(type->str);
	}
}
