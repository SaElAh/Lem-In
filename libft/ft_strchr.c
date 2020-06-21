/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:39:53 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/09/23 18:12:30 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (1)
	{
		if (s[i] == c)
		{
			str = (char *)&s[i];
			break ;
		}
		if (s[i++] == '\0')
			break ;
	}
	return (str);
}
