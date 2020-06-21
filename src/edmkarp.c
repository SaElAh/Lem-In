/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmkarp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 11:39:37 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:53:18 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"
#include "libft.h"

static uint32_t			len_path(t_edk *edk)
{
	int			i;
	uint32_t	len;

	len = 1;
	i = edk->sink;
	while (edk->pred_ind[i] >= 0)
	{
		i = edk->pred_ind[i];
		len++;
	}
	return (len);
}

static int				save_paths2(t_edk *edk, t_sets **sets,
							const size_t nb_vertices, const uint32_t len)
{
	uint64_t	tmp;

	tmp = ULLONG_MAX;
	if ((*sets)->nb_turns)
		tmp = (*sets)->nb_turns;
	if (fill_path(*edk, len, &(*sets)->paths))
		return (free_edk(edk, nb_vertices));
	(*sets)->nb_turns = calc_paths_capa(edk->nb_ants, &(*sets)->paths);
	if (tmp < (*sets)->nb_turns || (*sets)->paths->path_len > tmp)
	{
		(*sets)->paths = (*sets)->paths->next;
		free((*sets)->paths->prev->rooms_ind);
		free((*sets)->paths->prev);
		(*sets)->paths->prev = NULL;
	}
	return (0);
}

static int				save_paths(t_edk *edk, t_sets **sets,
							const size_t nb_vertices, const uint32_t len)
{
	size_t		i;
	static int	cpt;

	if (!edk->augmented_path)
		return (save_paths2(edk, sets, nb_vertices, len));
	else
	{
		(*sets)->nb_turns = calc_paths_capa(edk->nb_ants, &(*sets)->paths);
		if ((*sets)->next && (*sets)->nb_turns >= (*sets)->next->nb_turns)
			cpt++;
		if (cpt == 2)
			return (free_edk(edk, nb_vertices) == -1);
		ft_add_set(sets);
		i = 0;
		while (i < nb_vertices)
			ft_memset((void*)edk->flow[i++], 0, nb_vertices * sizeof(int));
	}
	return (0);
}

static int				edmkarploop(t_edk edk, t_sets **sets,
									size_t nb_vertices)
{
	int			i;
	uint32_t	len;

	len = len_path(&edk);
	i = edk.sink;
	while (edk.pred_ind[i] >= 0)
	{
		if (edk.flow[edk.pred_ind[i]][i] == -1)
		{
			edk.augmented_path = 1;
			edk.capacity[edk.pred_ind[i]][i] = 0;
			edk.capacity[i][edk.pred_ind[i]] = 0;
		}
		edk.flow[edk.pred_ind[i]][i] += 1;
		edk.flow[i][edk.pred_ind[i]] -= 1;
		i = edk.pred_ind[i];
	}
	return (save_paths(&edk, sets, nb_vertices, len));
}

int						edmkarp(t_graph *g, uint32_t nb_ants)
{
	t_edk		edk;
	int			flow;
	int			val;

	flow = 0;
	if (init_edk(&edk, g->nb_vertices, g->matrix->matrix, nb_ants))
		return (free_edk(&edk, g->nb_vertices));
	edk.src = g->matrix->ind_src;
	edk.sink = g->matrix->ind_sink;
	edk.augmented_path = 0;
	while (bfs(&edk, g->nb_vertices))
	{
		if ((val = edmkarploop(edk, &g->sets, g->nb_vertices)) == -1)
			return (-1);
		if (val == 1)
			return (flow);
		flow += 1;
		if (flow == 1 && g->sets->paths->path_len == 1)
			break ;
		edk.augmented_path = 0;
	}
	flow ? g->sets->nb_turns = calc_paths_capa(edk.nb_ants, &g->sets->paths)
				: 0;
	free_edk(&edk, g->nb_vertices);
	return (flow);
}
