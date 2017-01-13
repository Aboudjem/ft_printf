/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 23:12:24 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/13 03:59:51 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/includes/libft.h"
#include "stdio.h"

typedef struct	s_type
{
	int				d;
	unsigned int 	o;
	char 			c;
	char 			*s;
	va_list 		arguments;
}				t_conv;

#endif
