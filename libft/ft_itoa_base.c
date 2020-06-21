/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:26:59 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/02/21 19:37:39 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	ft_convert_val(int n)
{
	if (n >= 0 && n <= 9)
		return ((char)n + '0');
	else
		return ((char)n + 'A' - 10);
}

char		*ft_itoa_base(int n, int base)
{
	int		len;
	char	*res;
	int		sign;

	sign = 1;
	len = ft_nb_length(n, base);
	if (n < 0)
	{
		n = -n;
		sign = -1;
		len++;
	}
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[--len] = ft_convert_val(n % base);
		n = n / base;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
