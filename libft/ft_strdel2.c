/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:50:33 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/09/18 19:33:08 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_strdel2(char **as)
{
	if (as)
	{
		free(&(**as));
		*as = NULL;
		as = NULL;
	}
	return (as);
}
