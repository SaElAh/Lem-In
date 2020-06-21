/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:11:45 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/11/28 13:53:54 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		while (s[i] && (s[len - 1] == ' ' || s[len - 1] == '\n'
		|| s[len - 1] == '\t'))
			len--;
		if (!(str = (char *)malloc((len - i + 1) * sizeof(*str))))
			return (NULL);
		while (s[i] && i < len)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	else
		return (NULL);
}
