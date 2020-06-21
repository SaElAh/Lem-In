/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:00:41 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:50:32 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

int			main(void)
{
	t_pars		pars;
	t_graph		*graph;

	if (parser(&pars))
	{
		write(1, "ERROR\n", 6);
		return (1);
	}
	if (!(graph = new_graph(pars.list_rooms, &pars)))
	{
		free(pars.file);
		write(1, "ERROR\n", 6);
		return (1);
	}
	if (edmkarp(graph, pars.nb_ants) <= 0)
		write(1, "ERROR\n", 6);
	else
	{
		write(1, pars.file, ft_strlen(pars.file));
		print_ants_travel(pars.nb_ants, graph);
	}
	free(pars.file);
	free_graph(graph);
	return (0);
}
