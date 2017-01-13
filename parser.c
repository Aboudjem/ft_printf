/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 22:14:35 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/11 23:51:29 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdarg.h>
int	conv_d(char *s, int i)
{
	int j;
	j = 0;
	while (s[i])
	{
		if(s[i] == 'd')
		{
			printf("[%d], [%d]", i, j);
			return(1);
		}
		else
		{
			ft_putchar('-');
			ft_putchar('[');
			ft_putchar(s[i]);
			ft_putchar(']');
			ft_putchar('-');
			i++;
			j++;
		}
	}
return(0);
}


void	parser(char *s, ...)
{
	char *current;
	va_list arguments;

	va_start(arguments, s);
	while ((current = (char *)va_arg(arguments, char *)))
	{
		printf("\n\n\n%s", current);
	}
	va_end(arguments);
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{
			conv_d(s, i);
			i++;		
		}
		else
			i++;
	}
}

int		main()
{
	parser("BLABLA %d", 123,  "blabl", "lolilol");
return(0);
}
