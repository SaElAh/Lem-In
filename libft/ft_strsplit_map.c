/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:53 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/07/13 12:48:14 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	**ft_free_tab3(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_nbwords3(const char *str, char c)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
		cpt++;
	}
	return (cpt);
}

static int	ft_sizeword3(const char *str, char c, char d)
{
	int cpt;

	cpt = 0;
	while (1)
	{
		while (str[cpt] && (str[cpt] == c || str[cpt] == d))
			str++;
		while (str[cpt] && str[cpt] != c && str[cpt] != d)
			cpt++;
		if (!str[cpt] || str[cpt] == c)
			break ;
	}
	return (cpt);
}

static char	*ft_copy(char *tab, char **str, char c, char d)
{
	int		i;
	char	*s;
	char	*res;

	i = 0;
	s = *str;
	res = tab;
	while (*s && *s != c)
	{
		if (*s != d)
		{
			res[i] = *s;
			i++;
		}
		s++;
	}
	res[i] = '\0';
	*str = s;
	return (res);
}

char		**ft_strsplit_map(char *s, char c, char d)
{
	int		ind;
	int		word;
	char	**tab;
	int		nbwords;

	ind = 0;
	word = 0;
	if (!s)
		return (NULL);
	nbwords = ft_nbwords3(s, c);
	if (!(tab = ft_memalloc(nbwords)))
		return (NULL);
	while (nbwords--)
	{
		if (!(tab[ind] = ft_memalloc(ft_sizeword3(s, c, d))))
			return (ft_free_tab3(tab));
		while (s[0] && s[0] == c)
			s++;
		tab[ind] = ft_copy(tab[ind], &s, c, d);
		ind++;
		word = 0;
	}
	tab[ind] = 0;
	return (tab);
}
