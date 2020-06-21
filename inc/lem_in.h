/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:40:54 by sel-ahma          #+#    #+#             */
/*   Updated: 2019/11/29 19:45:57 by sel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>

# define HASHSIZE 2048

typedef struct s_listrooms	t_listrooms;

struct						s_listrooms
{
	t_listrooms		*next;
	char			*room;
	int				index;
	int				is_ant;
	uint32_t		hash;
	uint32_t		len;
};

typedef struct				s_paths
{
	struct s_paths	*next;
	struct s_paths	*prev;
	int				*rooms_ind;
	int64_t			capacity;
	uint32_t		ind;
	uint32_t		path_len;
}							t_paths;

typedef struct				s_sets
{
	struct s_sets	*next;
	struct s_sets	*prev;
	t_paths			*paths;
	uint64_t		nb_turns;
}							t_sets;

typedef struct				s_adjencymatrix
{
	int		**matrix;
	int		ind_src;
	int		ind_sink;
}							t_adjencymatrix;

typedef struct				s_graph
{
	t_adjencymatrix		*matrix;
	t_listrooms			**ptr_rooms;
	t_listrooms			*list_rooms;
	t_sets				*sets;
	size_t				nb_vertices;
}							t_graph;

typedef struct				s_edmkarp
{
	int				**flow;
	int				**capacity;
	int				*visited;
	int				*pred_ind;
	int				*queue;
	t_listrooms		*queue2;
	uint32_t		cur;
	uint32_t		last;
	uint32_t		src;
	uint32_t		sink;
	uint32_t		augmented_path;
	uint32_t		nb_ants;
}							t_edk;

typedef struct				s_parser
{
	t_listrooms		*list_rooms;
	char			*file;
	char			*rooms;
	char			*edges;
	char			*start;
	char			*end;
	char			*end_validity_file;
	uint32_t		nb_ants;
	uint32_t		nb_lines_rooms;
	uint32_t		ind_src;
	uint32_t		ind_sink;
}							t_pars;

typedef struct				s_util
{
	t_paths		*paths;
	int			nb_paths;
	int			capa_tot;
	int			dist_tot;
}							t_util;

typedef	struct				s_ants
{
	size_t		nb_lines;
	uint32_t	ind_room;
	uint16_t	ind_path;
	uint16_t	in_end;
}							t_ants;

typedef struct				s_updmatrix
{
	char		*src;
	char		*dest;
	size_t		nb_vertices;
	int			ind_src;
	int			ind_dest;
	int			i;
	int			j;
}							t_updmatrix;

typedef struct				s_init_room
{
	t_listrooms		**tab;
	t_listrooms		*tmp;
	uint32_t		i;
	uint32_t		j;
}							t_init_room;

typedef struct				s_saveroom
{
	t_listrooms		*tmp;
	char			*tmp_room;
	uint32_t		hash;
	uint32_t		ind;
	size_t			len;
}							t_saveroom;

/*
**	Graph functions
*/

t_graph						*new_graph(t_listrooms *r, t_pars *p);
int							init_utils_graph(t_graph *g, int ind_start,
							int ind_end);
int							is_empty_graph(t_graph *g);
int							upd_matrix(t_updmatrix *umat,
							t_listrooms **rooms, int **matrix);
void						free_graph(t_graph *g);
void						free_listrooms(t_listrooms *rooms);

/*
**	Print functions
*/

void						print_matrix(t_graph *g);
void						print_tab(char *str, int **tab, int nb_vertices);
void						print_paths(t_paths *p, t_listrooms **list_rooms);
void						print_ants_travel(uint32_t nb_ants, t_graph *g);
void						print_ants_travel_conditions_1(t_sets **sets);
void						print(size_t nb_ants, t_graph **g, t_ants *ants);

/*
**	Algo functions
*/

int							edmkarp(t_graph *g, uint32_t nb_ants);
int							bfs(t_edk *edk, size_t nb_vertices);
int							init_edk(t_edk *edk, size_t nb_vertices,
							int **matrix, uint32_t nb_ants);
int							free_edk(t_edk *edk, size_t nb_vertices);
void						ft_add_set(t_sets **sets);
int							fill_path(t_edk edk, uint32_t len, t_paths **paths);
void						ft_parse_paths(t_paths **paths);
void						ft_parse_paths1(t_paths **paths);
void						ft_calc_paths_capacities(uint32_t nb_ants,
							t_paths **paths_or);
uint64_t					calc_paths_capa(uint32_t nb_ants, t_paths
							**paths_or);
void						ft_set_capacities(t_paths **path,
							uint32_t nb_ants, uint32_t nb_turns);

/*
**	Parser functions
*/

int							init_pars(t_pars *pars);
int							parser(t_pars *pars);
int							ft_check_nb_ants(char **str_or, t_pars *pars);
int							ft_check_rooms(char **str_or, t_pars *pars);
int							ft_check_valid_coor(char **str_or);
int							ft_parse_commands(char **str_or, t_pars *pars);
int							ft_check_commentaries(char **str_or);
int							ft_check_edges(char **str_or, t_pars *pars);
int							ft_check_validity_rooms(char **str, t_pars *pars);
uint32_t					jenkins_hash(const uint8_t *key, size_t length);
int							ft_save_rooms(t_listrooms *rooms, char *room);

#endif
