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
    ft_putstr(type->space);
 if (ft_strlen(type->zero) > 0)
  ft_strdel(&type->zero);
 if (ft_strlen(type->space) > 0)
  ft_strdel(&type->space);
}

char skip_all(const char *s, int i)
{
    int j = 0;
    char *conv = " -#+.0123456789sSpdDioOuUxXcClhjz";
    while (conv[j] != '\0')
    {
	if (s[i] != conv[j])
	    j++;
	else
	    return (conv[j]);
    }
    return (0);
} 

t_conv	no_conv(const char *s, int i, t_conv type, t_flags flags)
{
	type.str = ft_strdup("");
	int j = 0;
	int k = 0;
	i -= type.count;
if(s[i + 1] && s[i] == '%')
	i++;
while(skip_all(s, i) != 0 && s[i] != '%')
	i++;

j = i;
while(s[j] != '\0' && s[j] != '%')
	{
		j++;
		k++;
	}
	type.str = ft_strsub(s, i, k);
		noconv_join(&type, flags);
	if (s[j] == '%')
	{
		type.count = j - 1;
		// ft_putnbr(type.count);
		// ft_putstr("ici");

	}
	else
		type.count = j;
	ft_putstr(type.str);



	return(type);
}



// int		count_char(const char *s, int i)
// {
// 	// char *str;
// 	(void)s;
// 	// i = i + type.count;
// 	ft_putnbr(i);
// 	// while()
// 	// {
// 	// 	ft_putchar(s[i]);
// 	// 	i++;
// 	// }
// 	return(i);
// }
