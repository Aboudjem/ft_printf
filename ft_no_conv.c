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

    // type->str = ft_strjoin(type->space, type->str);
    // type->str = ft_strjoin(type->zero, type->str);
 // if (ft_strlen(type->zero) > 0 || type->zero == NULL)
 //  ft_strdel(&type->zero);
 // if (ft_strlen(type->space) > 0 || type->space == NULL)
 //  ft_strdel(&type->space);
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
	// printf("[<%d>]\n", i);
	// ft_putstr(type->str);

	k = i;
	while (s[k+1] != '%')
		k++;
	// ft_putnbr(i);
	type->str = ft_strsub(s, i, k);
	noconv_join(type, flags);
	type->len_return = (int)ft_strlen(type->str);
	
	ft_putstr(type->str);
}
}

// 	// ft_putstr("ICI");
// 	while(is_flag(s, i) == 1 && s[i] != '%')
// 		i++;
// 	k = i;
// 	while(s[k] != '\0' && s[k + 1] != '%' && s[k])
// 		k++;
// 	// printf("[%c][%c][%c]", s[i], s[k], s[k + ((k + 1) - i)]);
// 	// printf("[%d][%d][%d]", i, k, (int)ft_strlen(s));
// 	if (i == k)
// 		k++;
// 	type->str = ft_strsub(s, i, k - i);
// 		noconv_join(type, flags);
// 	// printf("[%c][%d]", s[k], type->len_return);

// 		// if (s[k] + 1 && s[k] + 1 != '%')
// 	printf("[%d][%d][%d]", i, k, (int)ft_strlen(type->str));

// 			type->count =  k;//k - (int)ft_strlen(type->str); // 	2;//i + (k - i);//i;
// ft_putnbr(type->count);
// 	type->len_return = (int)ft_strlen(type->str);
// 	// printf("[%d][%d]", type->count, type->len_return);
// 	ft_putstr(type->str);
// }