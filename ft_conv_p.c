/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_CS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 08:50:39 by aboudjem          #+#    #+#             */
/*   Updated: 2017/02/04 08:50:41 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  p_fill_nodot(t_conv *type, t_flags flags, char *x)
{
  int len;
  len = (int)ft_strlen(type->str) + (int)ft_strlen(x);
  if (len == 0)
    len++;
  if (flags.pre == 0)
  {
    if (flags.zero == 0 && flags.pad > len)
      type->space = ft_strset(' ', flags.pad - len);
    else if (flags.zero == 1 && flags.pad > len)
      type->zero = ft_strset('0', flags.pad - len);
  }
  if (flags.neg == 1)
  {
        type->str = ft_strjoin(type->zero, type->str);
  	type->str = ft_strjoin(x, type->str);
    type->str = ft_strjoin(type->str, type->space);
  }
  else
  {
    type->str = ft_strjoin(type->zero, type->str);
  	type->str = ft_strjoin(x, type->str);
    type->str = ft_strjoin(type->space, type->str);
  }
  // type->str = ft_strjoin(x, type->str);
}

void	ft_hexa_p(t_conv *type)
{
	int mod = 0;
	int i = 0;
	unsigned long int nb;
	char *s = "0123456789abcdef";
	char *str;
	nb = (unsigned long int)type->p;
	if (nb == 0)
		type->str = ft_strdup("0");
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
	type->str = revert_str(str, i);
	}
}

void	conv_p(t_conv *type, t_flags flags)
{
	ft_hexa_p(type);
	char *x = ft_strdup("0x");
	// type->str = ft_strdup("");
	if (type->p > 0)
	type->str = ft_strjoin_free(&x,&type->str, 2);
	else
	{
	// type->str = ft_strjoin(x, type->str);
		p_fill_nodot(type, flags, x);
	ft_strdel(&x);
	// ft_putstr(type->str);
	}// ft_putstr(type->str);
	// if (flags.pre == 1)
	// 	p_join(type, flags);
type->len_return = (int)ft_strlen(type->str);
}



void p_join(t_conv *type, t_flags flags)
{

if (flags.pre == 0)
  s_fill_nodot(type, flags);
else if (flags.pre == 1)
{
    s_fill_space(type, flags);
    type->str = ft_strjoin(type->space, type->str);
}
 if (ft_strlen(type->zero) > 0)
  ft_strdel(&type->zero);
 if (ft_strlen(type->space) > 0)
  ft_strdel(&type->space);
 }