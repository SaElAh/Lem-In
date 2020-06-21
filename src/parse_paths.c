/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:48:36 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/24 17:02:57 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	parse_paths_loop(int32_t *i, t_paths *tmp1,
										t_paths **tmp2)
{
	uint32_t	j;

	j = 1;
	while (j < tmp1->path_len)
	{
		if (tmp1->rooms_ind[j] == (*tmp2)->rooms_ind[*i])
		{
			(*tmp2)->next ? (*tmp2)->next->prev = (*tmp2)->prev : 0;
			(*tmp2)->prev ? (*tmp2)->prev->next = (*tmp2)->next : 0;
			free((*tmp2)->rooms_ind);
			free((*tmp2));
			*tmp2 = tmp1;
			*i = -2;
			return ;
		}
		j++;
	}
}

void				ft_parse_paths1(t_paths **paths_or)
{
	t_paths	*tmp1;
	t_paths	*tmp2;
	int32_t	i;

	tmp1 = (*paths_or);
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			i = 1;
			while (tmp2 && i < (int32_t)tmp2->path_len && i != -1)
			{
				parse_paths_loop(&i, tmp1, &tmp2);
				i++;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
