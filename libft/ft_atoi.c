/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:00:38 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 20:09:46 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int64_t		ft_atoi(const char *str)
{
	uint8_t i;
	uint8_t sign;
	int64_t nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		str++;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		else
		{
			nb = (nb * 10) + str[i] - '0';
			i++;
		}
	}
	return (nb * sign);
}
