/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:57:42 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/13 04:05:03 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
#include <stdio.h>
#include <stdarg.h>
#include "libft/includes/libft.h"
#include "ft_printf.h"
/*
   char	*conv_int(const char *s, int i)
   {*/



char	*fill(const char *s, int i)
{
	int j = 0;
	char *str;
	int count = 0;
	int space = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		i++;
		j++;
	}
	str = (char*)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	i = i - j;
	while (count < j)
	{
		str[count] = s[i];
		count++;
		i++;
	}	
	count = 0;
	if (str[0] != '0')
		space = 1;

	count = ft_atoi(str);
	ft_putnbr(count);
	if(space == 1)
		ft_memset(str,' ', count);
	else
		ft_memset(str,'0', count);
	printf("%s", str);
	return(str);
}


int	which_flags(const char *s, int i)
{
	char *flags = " %#-+";
	int j = 0;
	int nb = 0;
	while (flags[j] != '\0')
	{
		if (s[i] != flags[j])
			j++;
		else
		{
			//ft_putchar('[');
			ft_putchar(flags[j]);
			//ft_putchar(']');
			i++;
			nb++;
			j = 0;
		}
	}

	//ft_putchar('\n');
	//ft_putnbr(nb);
	//ft_putchar('\n');
	return (0);
}
t_conv	which_conv(const char *s, int i, va_list arguments)
{
	int j = 0;
	i++;
	char *conv;
	t_conv type;
	conv = "sSpdDioOuUxXcC";
	while (conv[j] != '\0')
	{
		if (s[i] != conv[j])
		{
			j++;
		}
		else
		{
			if (conv[j] == 'd' || conv[j] == 'i')
			{
				type.d = va_arg(arguments, int);
				// printf("[[INT]]");
				//fill(s,i);
				ft_putnbr(type.d);
				return(type);
			}
			else if (conv[j] == 'o' || conv[j] == 'u' || conv[j] == 'x' || conv[j] == 'X')
			{
				type.o =	va_arg(arguments, unsigned int);
				//printf("[[UNSIGNED INT]]");
				ft_putnbr(type.o);
				return(type);
			}
			else if (conv[j] == 'c')
			{
				type.c = va_arg(arguments, int);
				ft_putnbr(type.c);//printf("[[CHAR]]");
				return(type);
			}
			else if (conv[j] == 's')
			{
				type.s = va_arg(arguments, char*);
				ft_putstr(type.s);
				if (!type.s)
					printf("[[CHAR*]]");
				return(type);
			}
			//		else if (conv[j] == 'o' || conv[j] == 'u' || conv[j] == 'x' || conv[j] == 'X')
			//return(1);
		}
	}
	which_flags(s, i);
	i++;
	printf("Erreur");
	return (type);
}
/*int	check(const char *s, int i)
  {
  while(s[i])
  {
  if(s[i] == '%')
  {
  which_conv(s, i);
  return(1);
  }
  else
  return(0);
  }
  return(0);
  }*/

int		ft_printf(const char *format, ...)
{
	int nb;
	int i = 0;
	t_conv type;
	va_start(type.arguments, format);
	while(format[i] != '\0')
	{
		if(format[i] == '%')
		{
			which_conv(format,i, type.arguments);
			i++;i++;
			// //type.s = va_arg(type.arguments, char*);
			// printf("[%s]", type.s);
//			ft_putstr("[here]");
			//current = va_arg(arguments, char*);
		}	
		else
		{
			ft_putchar(format[i]);
			i++;
		}
		//va_start(arguments, format);
		//check(format);
		// current = va_arg(arguments, char*);
		//	printf("%d", current);
	}
		va_end(type.arguments);
	return(0);
}
int	main()
{
	//printf("\n");
	ft_printf("coucou %% d slt ca va, %s %d", 12, 12);
	//printf("coucou [%4414.545d]", 12);
	printf("\n\n\n");
		//printf("coucou %d slt ca va, %s %d", 12, "yoyo", 11);
//	printf("coucou %s ", "abc");

	return(0);
}
