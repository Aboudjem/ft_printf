/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <aboudjem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 20:27:56 by aboudjem          #+#    #+#             */
/*   Updated: 2017/01/19 06:59:51 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#include "libft.h"
#include "stdio.h"

static void	itoa_isnegative(long long int n, long long int *negative, unsigned long long int *min)
{

	if (n < 0)
	{
		*min = n * (-1);
		*negative = 1;
	}
	else
		*min = n;
}

char		*ft_itoa(long long int n)
{
	long long int		tmp;
	int		len;
	long long int		negative;
	char	*str;
	unsigned long long int min;


	len = 2;
		// printf("\n\n[*--%lld--*]\n", n);

	negative = 0;
	itoa_isnegative(n, &negative, &min);
	tmp = min;
		// printf("\n\n[*--%lld--*]\n", min);

	while (tmp /= 10)
		len++;
		// printf("\n\n[*%d*]\n", len);

	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = min % 10 + '0';
		min = min / 10;
	}
	if (negative)
		str[0] = '-';
	// ft_putstr(str);
	return (str);
}