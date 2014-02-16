/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:28:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 03:47:20 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libmath.h>
#include <math.h>
#include <stddef.h>

t_vec3					viewplane_point(t_vec2 uv, t_engine *e)
{
	t_vec3				ret;

	ret.x = ((2.0f * uv.x - (float)e->img.width) / (float)e->img.width)
		* tan((float)e->cam.fovx);
	ret.y = ((2.0f * uv.y - (float)e->img.height) / (float)e->img.height)
		* tan((float)e->cam.fovy);
	ret.z = 100.0f;

	return (vec3_add(e->cam.position,
					 vec3_add(e->cam.direction, ret)));
}

void					camera_lookat(t_engine *e, t_vec3 target)
{
	e->cam.direction = vec3_sub(target, e->cam.position);
}

#include <stdio.h>
t_camera				*camera_update_viewplane(t_engine *e)
{
	if (!e)
		return (NULL);
	e->cam.viewplane.position
		= vec3_add(e->cam.position, vec3_sub(
					   vec3_add(
						   vec3_scale(e->cam.direction,
									e->cam.viewplane.distance),
						   vec3_scale(e->cam.up,
									  e->cam.viewplane.height * 0.5f)),
					   vec3_scale(e->cam.right,
								  e->cam.viewplane.width * 0.5f)));
	printf("Camera:\n"
		   "\tPos: %f %f %f\n"
		   "\tDir: %f %f %f\n"
		   "\tFovx: %f\n"
		   "\tFovy: %f\n"
		   "\tVP width: %f\n"
		   "\tVP height: %f\n"
		   "\tVP dist: %f\n"
		   "\tVP Pos: %f %f %f\n",
		   e->cam.position.x, e->cam.position.y, e->cam.position.z,
		   e->cam.direction.x, e->cam.direction.y, e->cam.direction.z,
		   e->cam.fovx, e->cam.fovy,
		   e->cam.viewplane.width, e->cam.viewplane.height,
		   e->cam.viewplane.distance,
		   e->cam.viewplane.position.x, e->cam.viewplane.position.y, e->cam.viewplane.position.z);
	return (&e->cam);
}


t_camera				*camera_init(t_engine *e, t_vec3 pos, t_vec3 lookat)
{
	if (!e)
		return (NULL);
	e->cam.position = pos;
	e->cam.direction = vec3_sub(lookat, pos);
	vec3_norm(&e->cam.direction);
	e->cam.fovx = PI / 4.0;
	e->cam.fovy = ((float)e->img.height / (float)e->img.width) * e->cam.fovx;
	e->cam.viewplane.width = 0.5;
	e->cam.viewplane.height = 0.35;
	e->cam.viewplane.distance = 1.0;
	e->cam.right = vec3_create(-1.0f, 0.0f, 0.0f);
	e->cam.up = vec3_create(0.0f, 1.0f, 0.0f);
	return (camera_update_viewplane(e));
}
