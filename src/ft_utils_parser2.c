/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:06:46 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/27 19:36:07 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int				ft_check_valid_coor(char **str_or)
{
	int		i;
	char	*str;

	str = *str_or;
	str = *str == '+' ? str + 1 : str;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	i = 0;
	while ((str[i] != ' ' && str[i] != '\n')
			&& (str[i] >= '0' && str[i] <= '9'))
		i++;
	if ((i >= 10 && *str > '2') || str[i] != ' ')
		return (1);
	str = &str[i + 1];
	str = *str == '+' ? str + 1 : str;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	i = 0;
	while ((str[i] != ' ' && str[i] != '\n')
			&& (str[i] >= '0' && str[i] <= '9'))
		i++;
	if ((i >= 10 && *str > '2') || str[i] != '\n')
		return (1);
	*str_or = &str[i + 1];
	return (0);
}

int				ft_check_commentaries(char **str_or)
{
	char	*str;

	str = *str_or;
	if (*str != '#')
		return (0);
	if (str[0] == '#' && str[1] && str[1] == '#')
		if (str[2] && (str[2] == 's' || str[2] == 'e'))
			if (ft_strnequ(str, "##start\n", 8)
				|| ft_strnequ(str, "##end\n", 6))
				return (1);
	while (*str && *str != '\n')
		str++;
	str = *str ? str + 1 : str;
	*str_or = str;
	return (0);
}

static int		ft_check_validity_edges(char **str_or)
{
	char *str;

	str = *str_or;
	if (*str == '#' || !*str)
		return (0);
	if (*str == '-' && *(str - 1) && *(str - 1) == '\n')
		return (1);
	while (*str && *str != '\n')
	{
		while (*str && *str != '-' && *str != '\n')
			str++;
		if (*str == '\n' && (*str_or = str))
			return (1);
		if (*str && *str == '-' && *(str - 1) != ' ' && *(str + 1) != ' '
				&& *(str - 1) != '\n' && *(str + 1) != '\n' && *(str + 1))
		{
			while (*str && *str != '\n')
				str++;
			*str_or = *str ? (str + 1) : str;
			return (0);
		}
		else
			break ;
	}
	return (1);
}

int				ft_check_edges(char **str_or, t_pars *pars)
{
	char *str;

	str = *str_or;
	pars->edges = str;
	while (*str)
	{
		if (ft_check_commentaries(&str))
		{
			*str_or = str;
			pars->end_validity_file = str;
			return (pars->end_validity_file == pars->edges);
		}
		if (ft_check_validity_edges(&str))
		{
			*str_or = str;
			pars->end_validity_file = str;
			return (pars->end_validity_file == pars->edges);
		}
	}
	*str_or = str;
	pars->end_validity_file = str;
	return (pars->end_validity_file == pars->edges);
}
