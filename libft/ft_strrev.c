/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:25:13 by sel-ahma          #+#    #+#             */
/*   Updated: 2018/08/06 16:06:15 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	count;
	int	len;
	int tiers;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	count = 0;
	while (count < len / 2)
	{
		tiers = str[count];
		str[count] = str[len - count - 1];
		str[len - count - 1] = tiers;
		count++;
	}
	return (str);
}
