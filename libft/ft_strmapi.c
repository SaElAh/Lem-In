/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:59:39 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:52:01 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ps[i] = (*f)(i, s[i]);
			i++;
		}
		ps[i] = '\0';
		return (ps);
	}
	else
		return (NULL);
}
