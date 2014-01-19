/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 00:09:46 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:17:55 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libft_memory.h>
#include <libft_string.h>
#include <libft_printf.h>
#include <sys/stat.h>
#include "map.h"
#include "ray_result.h"
#include "vec2.h"
#include "mlx_env.h"

int				map_block_type(struct s_map *map, int x, int y)
{
	if (!map || x >= map->width || y >= map->height || !map->data)
		return (0);
	return (map->data[y * map->width + x] - '0');
}

struct s_ray_result	map_shoot_ray(struct s_map *map,
								  struct s_vec2 position,
								  struct s_vec2 direction,
								  t_real step)
{
	t_real				length;
	t_vec2				start;
	t_vec2				end;
	t_real				cur;
	t_vec2				pos;
	t_ray_result		result;

	ray_result_init(&result);
	cur = 0.0f;
	start = position;
	end = vec2_add(start, vec2_scale(direction, MAX_RAY_LENGTH));
	length = vec2_length(vec2_sub(end, start));
	while (cur < MAX_RAY_LENGTH)
	{
		pos = ray_get_point(start, end, cur);
		result.position = pos;
		result.distance = cur;
		if (map_block_type(map, pos.x, pos.y) != 0)
		{
			result.hit = 1;
			return (result);
		}
		cur += step;
	}
	return (result);
}

struct s_vec2	map_find_first_block(struct s_mlx_env *env,
									 int startx,
									 int starty)
{
	t_vec2		ret;

	ret.x = ret.y = 0.0f;
	if (!env || !env->map)
		return (ret);
	ret.x = startx;
	ret.y = starty;
	while (ret.y < env->map->height)
	{
		while (ret.x < env->map->width)
		{
			if (!map_block_type(env->map, ret.x, ret.y))
			{
				ret.x *= env->map->scale;
				ret.y *= env->map->scale;
				return (ret);
			}
			ret.x++;
		}
			ret.y ++;
	}
	return (ret);
}

t_map			*map_reset(t_map *map)
{
	if (map->data)
		ft_strdel(&map->data);
	return (map_init(map));
}

t_map			*map_init(t_map *map)
{
	if (!map)
		return (map);
	map->width = 0;
	map->height = 0;
	map->scale = 1.0f;
	map->data = NULL;
	ft_strcpy(map->name, "");
	return (map);
}

t_map			*map_new()
{
	t_map		*ret;

	ret = ft_memalloc(sizeof(t_map));
	return (map_init(ret));
}

void			map_destroy(t_map **map)
{
	if (!map || !*map)
		return ;
	map_reset(*map);
	ft_memdel((void**)map);
}

int				map_load(const char *filename, t_map *map)
{
	int			fd;
	int			total;
	int			br;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	map_reset(map);
	read(fd, (char*)&map->name, MAX_MAP_NAME);
	read(fd, (char*)&map->width, sizeof(int));
	read(fd, (char*)&map->height, sizeof(int));
	read(fd, (char*)&map->scale, sizeof(int));
	total = sizeof(char) * map->width * map->height;
	map->data = ft_memalloc(total);
	if ((br = read(fd, map->data, total)) != total)
	{
		if (br == -1)
			ft_error("error: %s: map corrupted, couldn't "
					 "read datas from stream\n",
					 filename);
		else
			ft_error("error: %s: map data corrupted, "
					 "needed %i bytes, only got %i\n",
					 filename, total, br);
	}
	return (1);
}

int				map_save(const char *filename, t_map *map)
{
	int			fd;

	if (!filename || !map)
		return (0);
	fd = open(filename,
			  O_WRONLY | O_CREAT | O_TRUNC,
			  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		return (0);
	ft_strncpy(map->name, filename, sizeof(map->name));
	write(fd, (char*)&map->name, MAX_MAP_NAME);
	write(fd, (char*)&map->width, sizeof(int));
	write(fd, (char*)&map->height, sizeof(int));
	write(fd, (char*)&map->scale, sizeof(int));
	write(fd, map->data, sizeof(char) * map->width * map->height);
	close(fd);
	return (1);
}
