/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uoxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 08:50:41 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*revert_str(char *str, int i)
{
	char *tmp;
	int j = 0;
	tmp = ft_strnew(i+1);
	while(str[i] == '\0') 
		i--;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	ft_strdel(&str);
	return(tmp);
}

void	ft_hexa(t_conv *type)
{
	int mod = 0;
	int i = 0;
	unsigned long int nb;
	char *s = "0123456789abcdef";
	nb = type->u;
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
	int mod = 0;
	int i = 0;
	unsigned long int nb;
	char *s = "01234567";
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

void	conv_x_bigx(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_hexa(type);

	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);	
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	if (type->conv == 'X')
		ft_strtoupper(type->str);


	type->len_return = (int)ft_strlen(type->str);
}

void	conv_o_bigo(t_conv *type, t_flags flags)
{
	init(type);
	ft_hashtag(type, flags);
	ft_octal(type);
	type->len_d += ft_strlen(type->nb);
	if (flags.pre == 0)
		fill_nodot(type, flags);
	else
	{
		flags = handle_d(flags);	
		fill_zero(type, flags);
		fill_space(type, flags);
	}
	join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
}

