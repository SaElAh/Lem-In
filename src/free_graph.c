/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:01:21 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 20:02:29 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_sets(t_sets *sets)
{
	t_paths		*tmp;
	t_sets		*tmp2;

	while (sets->prev)
		sets = sets->prev;
	while (sets)
	{
		while (sets->paths)
		{
			tmp = sets->paths;
			sets->paths = sets->paths->next;
			free(tmp->rooms_ind);
			free(tmp);
		}
		tmp2 = sets;
		sets = sets->next;
		free(tmp2);
	}
}

void			free_graph(t_graph *g)
{
	size_t		i;

	i = 0;
	free_sets(g->sets);
	if (g->matrix)
		while (i < g->nb_vertices)
		{
			free(g->matrix->matrix[i]);
			i++;
		}
	free_listrooms(g->list_rooms);
	free(g->ptr_rooms);
	g->matrix ? free(g->matrix->matrix) : 0;
	free(g->matrix);
	free(g);
}
