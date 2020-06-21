/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:42:27 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:52:52 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)0;
	i = 0;
	while (1)
	{
		if (s[i] == c)
			str = (char *)&s[i];
		if (s[i++] == 0)
			break ;
	}
	return (str);
}
