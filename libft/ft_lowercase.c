/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:13:14 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/02/21 19:37:29 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_lowercase(char *res)
{
	char	*tmp;

	tmp = res;
	while (*tmp)
	{
		if (*tmp >= 'A' && *tmp <= 'Z')
			*tmp = *tmp + 32;
		tmp++;
	}
	return (res);
}
