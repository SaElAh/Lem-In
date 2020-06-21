/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_edk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:04:16 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 20:30:11 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "lem_in.h"
#include "libft.h"

void			ft_add_set(t_sets **sets)
{
	t_sets *tmp;

	tmp = malloc(sizeof(t_sets));
	tmp->prev = NULL;
	tmp->next = *sets;
	tmp->paths = NULL;
	tmp->nb_turns = INT_MAX;
	(*sets)->prev = tmp;
	*sets = tmp;
}

int				free_edk(t_edk *edk, size_t nb_vertices)
{
	size_t i;

	i = 0;
	free(edk->queue);
	free(edk->visited);
	free(edk->pred_ind);
	if (edk->flow != NULL)
	{
		while (i < nb_vertices)
		{
			free(edk->flow[i]);
			i++;
		}
		free(edk->flow);
	}
	return (-1);
}

static int		verif_mallocs_edk(t_edk *edk, size_t nb_vertices)
{
	size_t	i;

	if (!edk->queue || !edk->flow || !edk->visited || !edk->pred_ind)
		return (1);
	i = 0;
	while (i < nb_vertices)
	{
		if (!edk->flow[i])
			return (1);
		i++;
	}
	return (0);
}

int				init_edk(t_edk *edk, size_t nb_vertices,
						int **matrix, uint32_t nb_ants)
{
	size_t		i;

	edk->queue = malloc(sizeof(int) * nb_vertices);
	if ((edk->flow = malloc(sizeof(int*) * nb_vertices)))
	{
		i = 0;
		while (i < nb_vertices)
		{
			edk->flow[i] = (int*)ft_memalloc(sizeof(int) * (nb_vertices));
			i++;
		}
	}
	edk->capacity = matrix;
	edk->visited = malloc(sizeof(int) * nb_vertices);
	edk->pred_ind = malloc(sizeof(int) * nb_vertices);
	if (verif_mallocs_edk(edk, nb_vertices))
		return (1);
	edk->nb_ants = nb_ants;
	return (0);
}
