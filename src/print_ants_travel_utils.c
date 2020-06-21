/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants_travel_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:32:14 by cghanime          #+#    #+#             */
/*   Updated: 2019/11/29 19:57:06 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void		print_3(t_graph *g, t_ants *ants, uint32_t *cpt_ants,
							size_t i)
{
	g->ptr_rooms[g->sets->paths->rooms_ind
					[ants->ind_room]]->is_ant = 0;
	ants->ind_room += 1;
	if (g->sets->paths->rooms_ind[ants->ind_room]
			!= g->matrix->ind_sink)
		g->ptr_rooms[g->sets->paths->rooms_ind
						[ants->ind_room]]->is_ant = 1;
	if (g->sets->paths->rooms_ind[ants->ind_room]
			== g->matrix->ind_sink)
	{
		*cpt_ants += 1;
		ants->in_end = 1;
	}
	ft_printf("L%i-", i + 1);
	write(1, g->ptr_rooms[g->sets->paths->rooms_ind
							[ants->ind_room]]->room,
				g->ptr_rooms[g->sets->paths->rooms_ind
								[ants->ind_room]]->len + 1);
}

static void		print_2(uint32_t *cpt_ants, t_graph *g,
						t_ants *ants, size_t i)
{
	t_paths	*tmp;

	tmp = g->sets->paths;
	while (g->sets->paths && ants[i].ind_path != g->sets->paths->ind)
		g->sets->paths = g->sets->paths->next;
	if (g->sets->paths->rooms_ind[ants[i].ind_room] != g->matrix->ind_sink)
	{
		if (!g->ptr_rooms[g->sets->paths->rooms_ind
				[ants[i].ind_room + 1]]->is_ant)
			print_3(g, &ants[i], cpt_ants, i);
	}
	g->sets->paths = tmp;
}

void			print(size_t nb_ants, t_graph **g, t_ants *ants)
{
	uint32_t	i;
	uint32_t	cpt_ants;

	i = 0;
	cpt_ants = 0;
	while (cpt_ants < nb_ants)
	{
		i = 0;
		while (i < nb_ants)
		{
			if (!ants[i].in_end)
				print_2(&cpt_ants, *g, ants, i);
			i++;
		}
		write(1, "\n", 1);
		ants[0].nb_lines++;
	}
}
