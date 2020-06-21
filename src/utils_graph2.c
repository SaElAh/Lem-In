/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:00:41 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:58:47 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				find_ind_room(t_listrooms **rooms, char *room,
										size_t len_room, size_t nb_vertices)
{
	uint32_t		hash;
	size_t			i;
	t_listrooms		*tmp;

	i = 0;
	hash = jenkins_hash((uint8_t*)room, len_room);
	while (i < nb_vertices)
	{
		tmp = rooms[i];
		if (tmp && tmp->hash == hash)
			return (tmp->index);
		i++;
	}
	return (-1);
}

int						util_upd_matrix(int **matrix, t_updmatrix *umat,
									t_listrooms **rooms)
{
	while (umat->src[umat->i] && umat->src[umat->i] != '-')
		umat->i++;
	while (umat->src[umat->i] && umat->src[umat->j + umat->i + 1]
			&& umat->src[umat->j + umat->i + 1] != '\n')
		umat->j++;
	umat->ind_src = find_ind_room(rooms, umat->src, umat->i, umat->nb_vertices);
	umat->ind_dest = find_ind_room(rooms, &umat->src[umat->i + 1], umat->j,
									umat->nb_vertices);
	if (umat->ind_src >= 0 && umat->ind_dest >= 0)
	{
		matrix[umat->ind_src][umat->ind_dest] = 1;
		matrix[umat->ind_dest][umat->ind_src] = 1;
	}
	else
		return (1);
	return (0);
}

int						upd_matrix(t_updmatrix *umat, t_listrooms **rooms,
									int **matrix)
{
	while (*umat->src && umat->src < umat->dest)
	{
		umat->i = 0;
		umat->j = 0;
		if (*umat->src == '#')
		{
			ft_check_commentaries(&umat->src);
			continue ;
		}
		if (util_upd_matrix(matrix, umat, rooms))
			return (1);
		umat->src = umat->src[umat->j + umat->i + 1]
					? &umat->src[umat->j + umat->i + 2]
					: &umat->src[umat->j + umat->i + 1];
	}
	return (0);
}

int						init2(t_graph *g)
{
	size_t y;
	size_t x;

	y = 0;
	while (y < g->nb_vertices)
	{
		x = 0;
		if (!(g->matrix->matrix[y] = malloc(sizeof(int) * g->nb_vertices)))
		{
			while (x < y)
				free(g->matrix->matrix[x++]);
			free(g->matrix->matrix);
			free(g->matrix);
			return (1);
		}
		while (x < g->nb_vertices)
		{
			g->matrix->matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (0);
}

int						init_utils_graph(t_graph *g, int ind_src, int ind_sink)
{
	if (!(g->matrix = malloc(sizeof(t_adjencymatrix))))
		return (1);
	g->matrix->ind_src = ind_src;
	g->matrix->ind_sink = ind_sink;
	if (!(g->matrix->matrix = malloc(sizeof(int*) * g->nb_vertices)))
	{
		free(g->matrix);
		return (1);
	}
	return (init2(g));
}
