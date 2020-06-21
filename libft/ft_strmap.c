/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:48:44 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:51:55 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ps;

	i = 0;
	if (s)
	{
		if (!(ps = (char *)malloc(sizeof(*ps) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			ps[i] = (*f)(s[i]);
			i++;
		}
		ps[i] = '\0';
		return (ps);
	}
	else
		return (NULL);
}
