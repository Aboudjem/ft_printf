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
      type->space = ft_strset(' ', flags.pad - 1);
  else if (flags.zero == 1 && flags.pad >= 1)
      type->zero = ft_strset('0', flags.pad - 1);

    type->str = ft_strjoin(type->space, type->str);
    type->str = ft_strjoin(type->zero, type->str);

 // if (ft_strlen(type->zero) > 0 || type->zero == NULL)
 //  ft_strdel(&type->zero);
 // if (ft_strlen(type->space) > 0 || type->space == NULL)
 //  ft_strdel(&type->space);
}


void	no_conv(const char *s, int i, t_conv *type, t_flags flags)
{
	type->str = ft_strdup("");
	int k = 0;
// printf("\n\n<[-%d-]>\n\n", i);
if (!s[i + 1] && s[i] == '%')
	ft_putstr("LAWW");
	


while(is_flag(s, i) == 1 && s[i] != '%')
	i++;
// printf("\n\n[-%d-]\n\n", i);

k = i;
while(s[k] != '\0' && s[k + 1] != '%' && s[k])
		k++;
	// if (s[k + 1] == '%')
	// 	ft_putstr("LA");
	type->str = ft_strsub(s, i, (k+1)-i);
		noconv_join(type, flags);
// printf("\n\n/%s/\n\n", type->str);

// type->str = ft_strdup("");
type->count = k;
	// if (s[k] == '%')
	// 	type->count = k - 2;
}