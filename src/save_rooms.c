/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:12:45 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/24 22:12:36 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void					free_listrooms(t_listrooms *rooms)
{
	int			i;
	t_listrooms	*tmp;
	t_listrooms	*tmp2;

	i = 0;
	while (i < HASHSIZE)
	{
		tmp = &rooms[i];
		if (tmp->room && tmp->next)
		{
			tmp2 = tmp->next;
			while (tmp2)
			{
				tmp = tmp2;
				tmp2 = tmp->next;
				free(tmp);
			}
		}
		i++;
	}
	free(rooms);
}

extern inline uint32_t	jenkins_hash(const uint8_t *key, size_t length)
{
	size_t		i;
	uint32_t	hash;

	i = 0;
	hash = 0;
	while (i < length)
	{
		hash += key[i];
		hash += hash << 10;
		hash ^= hash >> 6;
		i++;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return (hash);
}

static inline size_t	ft_room_len(const char **room_or)
{
	size_t	len;
	size_t	cpt;
	char	*room;

	cpt = 0;
	room = (char*)*room_or;
	while (room[cpt] != ' ')
		cpt++;
	len = cpt;
	while (room[cpt] != '\n')
		cpt++;
	*room_or = &room[cpt + 1];
	return (len);
}

static inline void		init_utils(const char *room, t_saveroom *restrict s,
									const int kase)
{
	if (kase == 0)
	{
		s->tmp_room = (char*)room;
		s->len = ft_room_len((const char **)&s->tmp_room);
		s->hash = jenkins_hash((uint8_t*)room, s->len);
		return ;
	}
	s->tmp->next->is_ant = 0;
	s->tmp->next->room = (char*)room;
	s->tmp->next->len = s->len;
	s->tmp->next->hash = s->hash;
	s->tmp->next->next = NULL;
}

extern inline int		ft_save_rooms(t_listrooms *rooms, char *room)
{
	t_saveroom	s;

	init_utils(room, &s, 0);
	if (!rooms[(s.ind = s.hash % HASHSIZE)].room)
	{
		rooms[s.ind].room = room;
		rooms[s.ind].len = s.len;
		rooms[s.ind].hash = s.hash;
	}
	else
	{
		s.tmp = &rooms[s.ind];
		while (s.tmp->next)
		{
			if (ft_strnequ(room, s.tmp->room, s.len))
				return (1);
			s.tmp = s.tmp->next;
		}
		if (ft_strnequ(room, s.tmp->room, s.len))
			return (1);
		if (!(s.tmp->next = malloc(sizeof(t_listrooms))))
			return (1);
		init_utils(room, &s, 1);
	}
	return (0);
}
