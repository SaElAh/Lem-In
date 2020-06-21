/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:00:41 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 20:00:39 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_listrooms		**ft_init_tab_rooms(t_listrooms *rooms, t_pars *pars,
										size_t *nb_vertices)
{
	t_init_room s;

	if (!(s.tab = malloc(sizeof(t_listrooms*) * pars->nb_lines_rooms)))
		return (NULL);
	s.i = 0;
	s.j = 0;
	while (s.j < HASHSIZE)
	{
		s.tmp = &rooms[s.j];
		if (s.tmp->room)
		{
			while (s.tmp)
			{
				s.tab[s.i] = s.tmp;
				s.tmp->room == pars->start ? pars->ind_src = s.i : 0;
				s.tmp->room == pars->end ? pars->ind_sink = s.i : 0;
				s.tmp->index = s.i;
				s.tmp = s.tmp->next;
				s.i++;
			}
		}
		s.j++;
	}
	*nb_vertices = s.i;
	return (s.tab);
}

void			set_g(t_graph *restrict g, t_listrooms *rooms)
{
	g->sets->paths = NULL;
	g->sets->prev = NULL;
	g->sets->next = NULL;
	g->sets->nb_turns = 0;
	g->ptr_rooms = NULL;
	g->matrix = NULL;
	g->list_rooms = rooms;
}

void			*error_malloc_graph(t_graph *g, int kase)
{
	if (kase == 0)
	{
		free(g);
		return (NULL);
	}
	free_graph(g);
	return (NULL);
}

t_graph			*new_graph(t_listrooms *rooms, t_pars *pars)
{
	t_graph		*g;
	t_updmatrix	umat;

	if (!(g = malloc(sizeof(t_graph))))
		return (NULL);
	if (!(g->sets = malloc(sizeof(t_sets))))
		return (error_malloc_graph(g, 0));
	set_g(g, rooms);
	if (!(g->ptr_rooms = ft_init_tab_rooms(rooms, pars, &g->nb_vertices)))
		return (error_malloc_graph(g, 1));
	if (init_utils_graph(g, pars->ind_src, pars->ind_sink))
		return (error_malloc_graph(g, 1));
	umat.src = pars->edges;
	umat.dest = pars->end_validity_file;
	umat.nb_vertices = g->nb_vertices;
	upd_matrix(&umat, g->ptr_rooms, g->matrix->matrix);
	return (g);
}
