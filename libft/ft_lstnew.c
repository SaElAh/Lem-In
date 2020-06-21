/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:42:58 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:48:12 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*tmp;

	if (!(new = (t_list *)malloc(sizeof(*new) * (content_size + 1))))
		return (NULL);
	if (content == 0)
	{
		new->content = 0;
		new->content_size = 0;
	}
	else
	{
		if (!(tmp = (void *)malloc(sizeof(*tmp) * (content_size + 1))))
			return (NULL);
		tmp = ft_memcpy(tmp, content, content_size);
		new->content = tmp;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
