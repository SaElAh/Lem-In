/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:28:58 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:54:13 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <limits.h>
#include "lem_in.h"
#include "libft.h"

char		*ft_read_map(void)
{
	char	buf[4096];
	int		ret;
	char	*tmp;
	char	*stock;

	if ((read(STDIN_FILENO, buf, 0) == -1))
		return (NULL);
	if (!(stock = ft_strnew(0)))
		return (NULL);
	while ((ret = read(STDIN_FILENO, buf, 4095)) > 0)
	{
		buf[ret] = '\0';
		if (str_isascii(buf) || (!buf[0] && !*stock) || !stock)
		{
			free(stock);
			return (NULL);
		}
		tmp = stock;
		stock = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	return (stock);
}

int			ft_check_file(char *str, t_pars *pars)
{
	if (ft_check_nb_ants(&str, pars) || pars->nb_ants > INT_MAX)
		return (1);
	if (ft_check_rooms(&str, pars) || !pars->start || !pars->end)
		return (1);
	if (ft_check_edges(&str, pars))
		return (1);
	return (0);
}

int			parser(t_pars *pars)
{
	char	*str;

	str = NULL;
	if (init_pars(pars))
	{
		free(str);
		return (1);
	}
	if (!(str = ft_read_map()))
	{
		free_listrooms(pars->list_rooms);
		return (1);
	}
	pars->file = str;
	if (ft_check_file(str, pars))
	{
		free_listrooms(pars->list_rooms);
		free(str);
		return (1);
	}
	return (0);
}
