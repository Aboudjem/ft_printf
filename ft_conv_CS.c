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

int  s_pre(t_conv *type, t_flags flags)
{
  int i;
  i = 0;
  while (i + len_c(type->w[i]) <= flags.dot)
    i += len_c(type->w[i]);
  return(i);
}

void  s_fill_nodot(t_conv *type, t_flags flags)
{
  if (flags.pre == 0)
  {
    if (flags.zero == 0 && flags.pad > (int)ft_strlen(type->str))
      type->space = ft_strset(' ', flags.pad - (int)ft_strlen(type->str));
    else if (flags.zero == 1 && flags.pad > (int)ft_strlen(type->str))
      type->zero = ft_strset('0', flags.pad - (int)ft_strlen(type->str));
  }
  if (type->zero)
    type->str = ft_strjoin(type->zero, type->str);
  if (type->space)
    type->str = ft_strjoin(type->space, type->str);
}


void  s_fill_space(t_conv *type, t_flags flags)
{
  if (flags.pad > (int)ft_strlen(type->str))
    type->len_space = flags.pad - (int)ft_strlen(type->str);
  else
    type->len_space = 0;
  type->space = ft_strset(' ', type->len_space);
} 

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

void  conv_wc(unsigned long int c, t_conv *type)
{
  type->str = ft_strnew(4);
  if (c < 128 && c > 0)
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
  if (c == 0)
  {
    ft_putchar('\0');
    ft_bzero(type->str, 1);
    type->len_return = 1;
  }
  else
    type->len_return = len_c(c);//(int)ft_strlen(type->str);
}


void  conv_ws(t_conv *type, t_flags flags)
{
  int i;
  i = 0;
  char *tmp;
  tmp = ft_strdup("");
  // printf("]%S[", type->w);
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
     tmp = ft_strjoin_free(&tmp, &type->str, 3);
     i++;
   }
   type->str = ft_strdup(tmp);
   s_join(type, flags);

  type->len_return = (int)ft_strlen(type->str);     // ft_putstr(tmp);  // type->str = ft_strdup("");
}  
}

void s_join(t_conv *type, t_flags flags)
{
  int i;
  if (type->conv == 'S')
    i = s_pre(type, flags);
  else
    i = flags.dot;
  if (flags.pre == 0)
    s_fill_nodot(type, flags);
  else if (flags.pre == 1)
  {
    if (flags.dot < (int)ft_strlen(type->str))
      type->str = ft_strsub(type->str, 0, i);
    s_fill_space(type, flags);
    type->str = ft_strjoin(type->space, type->str);
  }
  if (ft_strlen(type->zero) > 0)
    ft_strdel(&type->zero);
  if (ft_strlen(type->space) > 0)
    ft_strdel(&type->space);
}