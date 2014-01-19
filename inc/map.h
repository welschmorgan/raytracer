/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:59:13 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:09:48 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <libft_types.h>

# define MAX_MAP_NAME 20

struct			s_vec2;
struct			s_mlx_env;

typedef struct	s_map
{
	int			width;
	int			height;
	t_real		scale;
	char		*data;
	char		name[MAX_MAP_NAME];
}				t_map;

#define MAX_RAY_LENGTH 1000.0f


t_map			*map_reset(t_map *map);
t_map			*map_init(t_map *map);
t_map			*map_new();
void			map_destroy(t_map **map);

int				map_load(const char *filename, t_map *map);
int				map_save(const char *filename, t_map *map);


int				map_block_type(struct s_map *map, int x, int y);
struct s_vec2	map_find_first_block(struct s_mlx_env *env,
									 int startx,
									 int starty);
struct s_ray_result	map_shoot_ray(struct s_map *env,
								  struct s_vec2 position,
								  struct s_vec2 direction,
								  t_real step);
#endif /* !MAP_H */
