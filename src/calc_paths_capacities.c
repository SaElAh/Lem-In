/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paths_capacities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:00:21 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:51:24 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"

uint64_t				calc_paths_capa(const uint32_t nb_ants,
										t_paths **paths_or)
{
	t_paths		*paths;
	uint64_t	nb_turns;
	uint64_t	nb_paths;
	uint64_t	dist_tot;

	nb_paths = 0;
	dist_tot = 0;
	paths = *paths_or;
	while (paths)
	{
		dist_tot += paths->path_len;
		nb_paths += 1;
		paths = paths->next;
	}
	nb_turns = (nb_ants + dist_tot);
	nb_turns /= nb_paths;
	nb_turns -= 1;
	return (nb_turns);
}

static uint32_t			ft_set_capacities2(t_paths **paths)
{
	uint32_t	sum;

	sum = 0;
	while ((*paths)->next)
	{
		(*paths)->capacity = 1;
		sum += 1;
		(*paths) = (*paths)->next;
	}
	(*paths)->capacity = 1;
	sum += 1;
	return (sum);
}

void					ft_set_capacities(t_paths **paths_or,
							const uint32_t nb_ants, const uint32_t nb_turns)
{
	t_paths		*paths;
	t_paths		*first;
	int64_t		tmp_capa;
	uint32_t	sum;

	paths = *paths_or;
	sum = ft_set_capacities2(&paths);
	first = paths;
	while (sum < nb_ants && paths)
	{
		tmp_capa = (int64_t)nb_turns + ((int64_t)nb_ants - sum)
						- ((int64_t)paths->path_len + (int64_t)nb_ants - sum);
		if (tmp_capa > 0)
		{
			sum += tmp_capa;
			paths->capacity += tmp_capa;
		}
		paths = paths->prev;
	}
	while (first && sum < nb_ants)
	{
		first->capacity += 1;
		sum += 1;
		first = first->prev;
	}
}
