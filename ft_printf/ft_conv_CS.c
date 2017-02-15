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


#include <stdio.h>


int len_c(unsigned int c)
{
  if (c < 128)
    return(1);
  else if (c < 2048)
    return(2);
  else if (c < 65536)
    return(3);
  else if (c < 1114112)
    return(4);
return(0);
}

void  conv_wc(unsigned int c, t_conv *type)
{
  type->str = ft_strnew(4);// if (MB_CUR_MAX == 1)
  if (c < 128)
    type->str[0] = c;
  else if (c < 2048)
  {
    type->str[0] = (192 | (c >> 6));
    type->str[1] = (128 | (c & 63));
  }
  else if (c < 65536)
  {
  	type->str[0] = (224 | (c >> 12));
    type->str[1] = (128 | ((c >> 6) & 63));
    type->str[2] = (128 | (c & 63));
  }
  else if (c < 1114112)
  {
   	type->str[0] = (240 | (c >> 18));
    type->str[1] = (128 | ((c >> 12) & 63));
    type->str[2] = (128 | ((c >> 6) & 63));
    type->str[3] = (128 | (c & 63));
  }
  if (type->c == 0 && type->c)
    type->len_return = 1;
  else if (!type->c)
    type->len_return = 1;
  else
    type->len_return = len_c(c);//(int)ft_strlen(type->str);
}

void  conv_ws(t_conv *type)
{
	int i;
	i = 0;
  char *tmp;
  type->len_return = 0;
	if (!type->w)
  {
    type->len_return = 6;
		type->str = ft_strdup("(null)");
  }
	else
	{
	 while (type->w[i] != '\0')
    {
      // ft_putstr(":AA:");
     conv_wc((unsigned int)type->w[i], type);
      tmp = ft_strdup(type->str);
      type->str = ft_strjoin_free(&type->str, &tmp, 3);
      // ft_putstr(type->str);
      i++;
    }
 //      // conv_wc(type->w[i], type);
 //      // type->str = ft_strjoin_free(&type->str, &wc, 3);
 //      i++;
  	// }
	}
}