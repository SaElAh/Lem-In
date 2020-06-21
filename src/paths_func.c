/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:17:47 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/24 21:14:33 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static inline int	check_colli(t_paths *path, t_edk edk)
{
	int		i;
	int		cpt;

	while (path)
	{
		i = edk.sink;
		while (i >= 0)
		{
			cpt = 1;
			while (cpt < (int)path->path_len)
			{
				if (path->rooms_ind[cpt] == i)
					return (1);
				cpt++;
			}
			i = edk.pred_ind[i];
		}
		path = path->next;
	}
	return (0);
}

static inline void	init_path(t_paths **paths, t_paths *tmp, int len, int kase)
{
	if (kase == 0)
	{
		(*paths)->path_len = len - 1;
		(*paths)->capacity = 0;
		(*paths)->ind = 1;
		(*paths)->next = NULL;
		(*paths)->prev = NULL;
	}
	else
	{
		tmp->path_len = len - 1;
		tmp->capacity = 0;
		tmp->next = *paths;
		tmp->prev = NULL;
		(*paths)->prev = tmp;
		*paths = tmp;
	}
}

static inline int	fill_path2(t_edk edk, const uint32_t len, t_paths **paths)
{
	t_paths		*tmp;
	int			tmp2;
	uint32_t	cpt;

	if (check_colli(*paths, edk))
		return (0);
	if (!(tmp = malloc(sizeof(t_paths))))
		return (1);
	if (!(tmp->rooms_ind = malloc(sizeof(int) * (len))))
	{
		free(tmp);
		return (1);
	}
	tmp->ind = (*paths)->ind + 1;
	tmp2 = edk.sink;
	cpt = len - 1;
	while (tmp2 >= 0)
	{
		tmp->rooms_ind[cpt] = tmp2;
		tmp2 = edk.pred_ind[tmp2];
		cpt--;
	}
	init_path(paths, tmp, len, 1);
	return (0);
}

extern inline int	fill_path(t_edk edk, uint32_t len, t_paths **paths)
{
	uint32_t	cpt;
	int			tmp2;

	if (!(*paths))
	{
		cpt = len - 1;
		if (!((*paths) = malloc(sizeof(t_paths))))
			return (1);
		if (!((*paths)->rooms_ind = malloc(sizeof(int) * (len))))
		{
			free((*paths));
			return (1);
		}
		tmp2 = edk.sink;
		while (tmp2 >= 0)
		{
			(*paths)->rooms_ind[cpt] = tmp2;
			tmp2 = edk.pred_ind[tmp2];
			cpt--;
		}
		init_path(paths, NULL, len, 0);
	}
	else
		return (fill_path2(edk, len, paths));
	return (0);
}
