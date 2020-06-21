/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:02:58 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:51:45 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		n;
	size_t		len;
	const char	*pdst;
	const char	*psrc;

	n = size;
	pdst = dst;
	psrc = src;
	while (n-- != 0 && *dst != '\0')
		dst++;
	len = dst - pdst;
	n = size - len;
	if (n-- == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (n)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (len + (src - psrc));
}
