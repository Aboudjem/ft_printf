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


void noconv_join(t_conv *type, t_flags flags)
{

  if (flags.zero == 0 && flags.pad >= 1)
      {
      	type->space = ft_strset(' ', flags.pad - 1);
      	if (flags.neg == 1)
    	type->str = ft_strjoin(type->str, type->space);
      	else
    	type->str = ft_strjoin(type->space, type->str);
		      		
      }
  else if (flags.zero == 1 && flags.pad >= 1)
      {
      	type->zero = ft_strset('0', flags.pad - 1);
    	type->str = ft_strjoin(type->zero, type->str);
      }
}


void	no_conv(const char *s, int i, t_conv *type, t_flags flags)
{
	int k = 0;
if (!s[i + 1] && s[i] == '%')
{
	type->len_return = 0;
	type->str = ft_strdup("");
}
else
{
	k = i;
	while (s[k+1] != '%')
		k++;
	type->str = ft_strsub(s, i, k);
	noconv_join(type, flags);
	// type->len_return = (int)ft_strlen(type->str);
}
}