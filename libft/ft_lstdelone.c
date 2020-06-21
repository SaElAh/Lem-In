/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:39:14 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:47:27 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	if (*alst != NULL && (*del) != NULL)
	{
		current = *alst;
		(*del)((void *)current->content, current->content_size);
		ft_memdel((void **)alst);
	}
}
