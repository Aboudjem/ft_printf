/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 06:05:04 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/23 18:04:29 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char		*ft_litoa(unsigned long long int n)
{
	unsigned long long int		tmp;
	int		len;
	char	*str;
	tmp = n;

	len = 2;
	while (tmp /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void	ft_stroupper(char *s)
{
	int i;
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

void	*ft_strset(int c,size_t len)
{
	char *s;

	s = ft_strnew(len);

	while (len > 0)
	{
		len--;
		s[len] = c;
	}
	return (s);
}

int	ft_len_int(int nbr)
{
	int i;
	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return(i);
}


 void init_flags(t_flags *flags)
{
	flags->pre = 0;
	flags->champs = 0;
    flags->space = 0;
    flags->zero = 0;
    flags->neg = 0;
    flags->plus = 0;
    flags->prcnt = 0;
    flags->hash = 0;
    flags->dot = 0;
    flags->ll = 0;
    flags->l = 0;
    flags->h = 0;
    flags->hh = 0;
    flags->j = 0;
    flags->z = 0;
    flags->negdot = 0;
    flags->pad = 0;
}