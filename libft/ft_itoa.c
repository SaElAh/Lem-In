/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:26:59 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/12/16 19:18:30 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	sign = 1;
	len = ft_nb_length(n, 10);
	if (n < 0)
	{
		sign = -1;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (len)
	{
		str[len--] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[len] = n + '0';
	else
		str[len] = '-';
	return (str);
}
