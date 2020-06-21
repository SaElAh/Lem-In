/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:30:51 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:52:34 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *src, const char *target, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = ft_memalloc(n);
	str = ft_strncpy(str, src, n);
	if (ft_strstr((const char *)str, target))
		return (ft_strstr(src, target));
	return (0);
}
