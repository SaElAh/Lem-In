/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pars_checknbants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:27:05 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 20:11:08 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int			init_pars(t_pars *pars)
{
	pars->nb_ants = 0;
	pars->nb_lines_rooms = 0;
	pars->file = NULL;
	pars->start = NULL;
	pars->end = NULL;
	pars->end_validity_file = NULL;
	pars->rooms = NULL;
	pars->edges = NULL;
	if (!(pars->list_rooms = ft_memalloc(sizeof(t_listrooms) * HASHSIZE)))
		return (1);
	return (0);
}

int			ft_check_nb_ants(char **str_or, t_pars *pars)
{
	int		i;
	char	*str;

	while (**str_or == '#')
		if (ft_check_commentaries(str_or))
			return (1);
	str = *str_or;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if ((i >= 10 && *str > '2') || str[i] != '\n')
		return (1);
	if ((pars->nb_ants = ft_atoi(*str_or)) <= 0)
		return (1);
	*str_or = &str[i + 1];
	pars->rooms = *str_or;
	return (pars->nb_ants == 0);
}
