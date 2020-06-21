/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:20:57 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:47:44 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tail;

	if (!(lst || (*f)))
		return (NULL);
	tail = f(lst);
	head = tail;
	if (head == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tail->next = f(lst);
		if (tail->next == NULL)
			return (NULL);
		tail = tail->next;
	}
	return (head);
}
