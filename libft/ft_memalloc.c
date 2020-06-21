/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:35:40 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/02/09 18:37:48 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (!(str = (void *)malloc(sizeof(void *) * (size + 1))))
		return (NULL);
	if (str == NULL || size > 4294967295)
		return (NULL);
	str = ft_bzero(str, size + 1);
	return (str);
}
