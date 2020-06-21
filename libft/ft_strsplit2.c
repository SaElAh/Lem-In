/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:53 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/02/23 14:51:46 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_nbwords(const char *str, char c, char d)
{
	int i;
	int cpt;

	cpt = 0;
	i = 0;
	while (str[i] && (str[i] == c || str[i] == d))
		i++;
	while (str[i])
	{
		while (str[i] && (str[i] != c && str[i] != d))
			i++;
		while (str[i] && (str[i] == c || str[i] == d))
			i++;
		cpt++;
	}
	return (cpt);
}

static int	ft_sizeword(const char *str, char c, char d)
{
	int cpt;

	cpt = 0;
	while (str[cpt] && (str[cpt] == c || str[cpt] == d))
		str++;
	while (str[cpt] && (str[cpt] != c && str[cpt] != d))
		cpt++;
	return (cpt);
}

char		**ft_strsplit2(char const *s, char c, char d)
{
	int		ind;
	int		word;
	char	**tab;
	int		nbwords;

	ind = 0;
	word = 0;
	if (!s)
		return (NULL);
	nbwords = ft_nbwords(s, c, d);
	if (!(tab = ft_memalloc(nbwords)))
		return (NULL);
	while (nbwords--)
	{
		if (!(tab[ind] = ft_memalloc(ft_sizeword(s, c, d))))
			return (NULL);
		while (s[0] && (s[0] == c || s[0] == d))
			s++;
		while (s[0] && s[0] != c && s[0] != d)
			tab[ind][word++] = *s++;
		tab[ind++][word] = '\0';
		word = 0;
	}
	tab[ind] = 0;
	return (tab);
}
