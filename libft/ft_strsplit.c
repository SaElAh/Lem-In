/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:53 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/09/23 18:12:05 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_free_tab(char **tab)
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

static int	ft_nbwords(const char *str, char c)
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

static int	ft_sizeword(const char *str, char c)
{
	int cpt;

	cpt = 0;
	while (str[cpt] && str[cpt] == c)
		str++;
	while (str[cpt] && str[cpt] != c)
		cpt++;
	return (cpt);
}

char		**ft_strsplit(char const *s, char c)
{
	int		ind;
	int		word;
	char	**tab;
	int		nbwords;

	ind = 0;
	word = 0;
	if (!s)
		return (NULL);
	nbwords = ft_nbwords(s, c);
	if (!(tab = ft_memalloc(nbwords)))
		return (NULL);
	while (nbwords--)
	{
		if (!(tab[ind] = ft_memalloc(ft_sizeword(s, c))))
			return (ft_free_tab(tab));
		while (s[0] && s[0] == c)
			s++;
		while (s[0] && s[0] != c)
			tab[ind][word++] = *s++;
		tab[ind++][word] = '\0';
		word = 0;
	}
	tab[ind] = 0;
	return (tab);
}
