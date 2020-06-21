/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:37:12 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 19:36:10 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_check_validity_rooms(char **str_or, t_pars *pars)
{
	char	*str;
	char	*to_save;

	if (**str_or == '#')
		return (0);
	str = *str_or;
	if (*str == 'L' || *str == '\n' || !(to_save = str))
		return (1);
	while (*str && *str != ' ' && *str != '-' && *str != '\n')
		str++;
	if (*str != ' ' || !*str)
		return (1);
	str++;
	if (ft_check_valid_coor(&str))
		return (1);
	if (ft_save_rooms(pars->list_rooms, to_save))
	{
		*str_or = to_save;
		return (1);
	}
	*str_or = str;
	pars->nb_lines_rooms += 1;
	return (0);
}

static int		ft_parse_commentaries(char **str_or, t_pars *pars)
{
	char	*str;
	int		check_cmd;

	str = *str_or;
	if (*str != '#')
		return (0);
	if (!(check_cmd = ft_parse_commands(str_or, pars)))
		return (0);
	else if (check_cmd == 1)
		return (1);
	while (*str && *str != '\n')
		str++;
	*str_or = str;
	if ((*str != '\n' && *str) || !*str)
		return (1);
	*(str_or) += 1;
	return (0);
}

static int		ft_check_validity_edge(char *str)
{
	if (!*str || *str == '#')
		return (1);
	while (*str && *str != '\n')
	{
		str++;
		if (*str == '-' && *(str - 1) != ' ' && *(str + 1) != ' '
				&& *(str - 1) != '\n' && *(str + 1) != '\n'
				&& *(str + 1))
			return (0);
	}
	return (1);
}

int				ft_check_rooms(char **str_or, t_pars *pars)
{
	char	*str;

	str = *str_or;
	while (*str)
	{
		if (ft_parse_commentaries(&str, pars))
		{
			*str_or = str;
			return (ft_check_validity_edge(str));
		}
		if (ft_check_validity_rooms(&str, pars))
		{
			if (*str_or != str)
			{
				*str_or = str;
				return (ft_check_validity_edge(str));
			}
			return (1);
		}
	}
	*str_or = str;
	return (0);
}
