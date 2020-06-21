/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:29:55 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:53:38 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *src, const char *target)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)src;
	if (target[0] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i + j] == target[j])
		{
			if (target[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
