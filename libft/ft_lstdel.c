/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:00:57 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:47:18 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*current;

	if (*alst != NULL && (*del) != NULL)
	{
		current = *alst;
		while (current)
		{
			next = current->next;
			(*del)((void *)current->content, current->content_size);
			current = next;
			free(current);
		}
		ft_memdel((void **)alst);
	}
}
