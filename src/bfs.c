/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:39:37 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 18:31:55 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static inline void		enqueue(t_edk *edk, size_t dest)
{
	edk->queue[edk->last] = dest;
	edk->last += 1;
	edk->visited[dest] = 1;
}

static inline uint32_t	dequeue(t_edk *edk)
{
	uint32_t	from;

	from = edk->queue[edk->cur];
	edk->cur += 1;
	return (from);
}

static inline void		init_bfs(t_edk *edk, size_t nb_vertices)
{
	ft_memset((void*)edk->visited, 0, nb_vertices * sizeof(int));
	edk->cur = 0;
	edk->last = 0;
	enqueue(edk, edk->src);
	edk->pred_ind[edk->src] = -1;
}

int						bfs(t_edk *edk, size_t nb_vertices)
{
	uint32_t		from;
	uint32_t		dest;
	int32_t			*tab;

	init_bfs(edk, nb_vertices);
	while (edk->cur != edk->last && (from = dequeue(edk)) != edk->sink)
	{
		dest = 0;
		tab = *(edk->capacity + from);
		while (dest < nb_vertices)
		{
			if (*(tab + dest))
				if (edk->flow[from][dest] <= 0)
				{
					if (edk->visited[dest] == 0)
					{
						enqueue(edk, dest);
						edk->pred_ind[dest] = from;
					}
				}
			dest++;
		}
	}
	return (edk->visited[edk->sink] == 1);
}
