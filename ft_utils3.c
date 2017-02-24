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

char	*revert_str(char *str, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = ft_strnew(i + 1);
	while (str[i] == '\0')
		i--;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	ft_strdel(&str);
	return (tmp);
}

void	ft_hexa(t_conv *type)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	s = "0123456789abcdef";
	nb = type->u;
	i = 0;
	if (nb == 0)
		type->nb = ft_strdup("0");
	else
	{
		type->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 16);
			type->nb[i] = s[mod];
			i++;
			nb /= 16;
		}
		type->nb = revert_str(type->nb, i);
	}
}

void	ft_octal(t_conv *type)
{
	int					mod;
	int					i;
	unsigned long int	nb;
	char				*s;

	mod = 0;
	i = 0;
	s = "01234567";
	nb = type->u;
	if (type->u == 0)
		type->nb = ft_strdup("0");
	else
	{
		type->nb = ft_strnew(22);
		while (nb > 0)
		{
			mod = (nb % 8);
			type->nb[i] = s[mod];
			i++;
			nb /= 8;
		}
		type->nb = revert_str(type->nb, i);
	}
}

void	ft_hashtag(t_conv *type, t_flags flags)
{
	if (flags.hash == 1)
	{
		if (type->conv == 'x' || type->conv == 'X')
		{
			if (type->u > 0)
				type->sign = "0x";
			else
				type->sign = "";
		}
		else if (type->conv == 'o' && type->u > 0)
			type->sign = "0";
		else if (type->conv == 'o' && flags.hash == 1 && flags.pre == 1)
			type->sign = "0";
		type->len_d += (int)ft_strlen(type->sign);
	}
}