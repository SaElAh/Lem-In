/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:37:36 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/12/07 17:37:40 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int		ft_parse_end(char **str_or, t_pars *pars)
{
	char	*str;

	str = *str_or;
	pars->end = NULL;
	str = &str[6];
	while (*str == '#')
		if (ft_check_commentaries(&str))
			return (1);
	if ((*str_or = str) && !ft_check_validity_rooms(str_or, pars))
		pars->end = str;
	return (pars->end == NULL);
}

static int		ft_parse_start(char **str_or, t_pars *pars)
{
	char	*str;

	str = *str_or;
	pars->start = NULL;
	str = &str[8];
	while (*str == '#')
		if (ft_check_commentaries(&str))
			return (1);
	*str_or = str;
	if (!ft_check_validity_rooms(str_or, pars))
		pars->start = str;
	return (pars->start == NULL);
}

int				ft_parse_commands(char **str_or, t_pars *pars)
{
	if (ft_strnequ(*str_or, "##start\n", 8))
	{
		return (ft_parse_start(str_or, pars));
	}
	if (ft_strnequ(*str_or, "##end\n", 6))
	{
		return (ft_parse_end(str_or, pars));
	}
	return (2);
}
