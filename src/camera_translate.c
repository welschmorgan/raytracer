/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 23:23:34 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:24:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "map.h"
#include "vec2.h"

int				camera_translate(t_camera *cam,
								 struct s_map *map,
								 t_real delta_x,
								 t_real delta_y)
{
	t_vec2		new_pos;

	if (!cam)
		return (0);
	new_pos.x = cam->position.x + delta_x;
	new_pos.y = cam->position.y + delta_y;
	if (((new_pos.x >= map->width * map->scale) || new_pos.x < 0)
		|| ((new_pos.y >= map->height * map->scale) || new_pos.y < 0)
		|| map_block_type(map, new_pos.x / map->scale, new_pos.y / map->scale))
		return (0);
	cam->position = new_pos;
	return (1);
}
