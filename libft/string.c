/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:34:03 by stdenis           #+#    #+#             */
/*   Updated: 2019/09/24 15:28:52 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_with_string(char *value, t_printf *tab, int len, char fill)
{
	int		i;

	i = -1;
	while (!(tab->arg.flag & MINUS) && tab->arg.larg-- > 0)
		fill_buffer(fill, tab);
	while (value[i] && len >= 0)
	{
		i++;
		len--;
		fill_buffer(value[i], tab);
	}
	while ((tab->arg.flag & MINUS) && tab->arg.larg-- > 0)
		fill_buffer(fill, tab);
}

void		check_string(char *value, t_printf *tab)
{
	int		len;

	if (value == NULL)
	{
		len = (tab->arg.flag & PREC) ? tab->arg.prec : 6;
		tab->arg.larg -= (tab->arg.larg > 0) ? len : 0;
		if (tab->arg.flag & ZERO && !(tab->arg.flag & MINUS))
			fill_with_string("(null)", tab, len, '0');
		else
			fill_with_string("(null)", tab, len, ' ');
	}
	else
	{
		len = ft_strlen(value);
		if (tab->arg.flag & PREC && tab->arg.type == S)
			len = (len < tab->arg.prec) ? len : tab->arg.prec;
		tab->arg.larg -= (tab->arg.larg > 0) ? len : 0;
		if (tab->arg.flag & ZERO && !(tab->arg.flag & MINUS))
			fill_with_string(value, tab, len, '0');
		else
			fill_with_string(value, tab, len, ' ');
	}
}

void		get_string(va_list ap, void *ptr)
{
	t_printf *tab;

	tab = (t_printf*)ptr;
	check_string(va_arg(ap, char *), tab);
}
