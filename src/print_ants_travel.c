/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants_travel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:53:05 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:56:29 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"
#include "libft.h"

static void		give_paths(t_paths *paths, t_ants *ants, uint32_t nb_ants)
{
	size_t		i;
	uint32_t	cpt;

	i = 0;
	while (i < nb_ants && paths)
	{
		cpt = 0;
		if (paths->capacity > 0)
		{
			while (i < nb_ants && cpt < paths->capacity)
			{
				ants[i++].ind_path = paths->ind;
				cpt++;
			}
		}
		paths = paths->next;
	}
}

static void		choose_set(t_sets **sets)
{
	t_sets		*tmp_sets;
	uint32_t	min;

	min = UINT_MAX;
	tmp_sets = *sets;
	while (tmp_sets && tmp_sets->paths)
	{
		min = tmp_sets->nb_turns < min ? tmp_sets->nb_turns : min;
		tmp_sets = tmp_sets->next;
	}
	tmp_sets = *sets;
	while (tmp_sets)
	{
		if (tmp_sets->nb_turns == min)
			break ;
		tmp_sets = tmp_sets->next;
	}
	*sets = tmp_sets;
}

void			print_ants_travel(uint32_t nb_ants, t_graph *g)
{
	t_ants		*ants;

	if (!(ants = ft_memalloc(sizeof(t_ants) * nb_ants)))
	{
		write(STDERR_FILENO, "Malloc failed in print_ants_travel... \
Maybe too many ants ?\n", 64);
		return ;
	}
	write(1, "\n", 1);
	choose_set(&g->sets);
	ft_set_capacities(&g->sets->paths, nb_ants, g->sets->nb_turns);
	give_paths(g->sets->paths, ants, nb_ants);
	print(nb_ants, &g, ants);
	ft_printf("\nNb turns [%zu]\n", ants[0].nb_lines);
	free(ants);
	return ;
}
