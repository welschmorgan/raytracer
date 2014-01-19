/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:59:37 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:27:33 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft_memory.h>
#include "camera.h"
#include "map.h"
#include "mlx_env.h"
#include "ray_result.h"
#include <math.h>

/*
**static t_vec2	VEC2_UNIT_X = {1.0f, 0.0f};
**static t_vec2	VEC2_UNIT_Y = {0.0f, 1.0f};
**static t_vec2	VEC2_UNIT_SCALE = {1.0f, 1.0f};
*/

t_camera		*camera_set(t_camera *cam,
							t_vec2 position,
							t_vec2 direction)
{
	if (!cam)
		return (cam);
	cam->position = position;
	cam->direction = direction;
	return (cam);
}

t_camera		*camera_init(struct s_mlx_env *env,
							 t_camera *cam)
{
	t_vec2		pos;

	if (!cam || !env || !env->height)
		return (cam);
	pos.x = 5;
	pos.y = 5;
	vec2_set(&cam->position, pos.x, pos.y);
	vec2_set(&cam->direction, 0.0f, 1.0f);
	cam->fovy = (env->width / env->height);
	if (!cam->fovy)
		cam->fovy = 1.0f;
	cam->fov = 60.0f * cam->fovy;
	return (cam);
}

t_camera		*camera_new(struct s_mlx_env *env,
							t_vec2 position,
							t_vec2 look_at)
{
	t_camera	*cam;

	cam = ft_memalloc(sizeof(t_camera));
	if (!cam)
		return (cam);
	camera_init(env, cam);
	camera_set(cam, position, vec2_sub(look_at, position));
	return (cam);
}
