/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:28:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:43:26 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libmath.h>
#include <math.h>
#include <stddef.h>

t_vec3					camera_viewplane_point(t_engine *e, t_vec2 pixel)
{
	t_vec3				ret;
	t_real				xindent;
	t_real				yindent;

	xindent = e->cam.viewplane.width / (float)e->img.width;
	yindent = e->cam.viewplane.height / (float)e->img.height;
	ret = vec3_sub(
		vec3_add(e->cam.viewplane.position,
				 vec3_scale(vec3_scale(e->cam.right, xindent), pixel.x)),
		vec3_scale(vec3_scale(e->cam.up, yindent), pixel.y));
	return (ret);
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
	return (&e->cam);
}


t_camera				*camera_init(t_engine *e, t_vec3 pos, t_vec3 lookat)
{
	if (!e)
		return (NULL);
	e->cam.position = pos;
	e->cam.direction = vec3_sub(lookat, pos);
	vec3_norm(&e->cam.direction);
	e->cam.engine = e;
	e->cam.viewplane.camera = &e->cam;
	e->cam.fovx = PI / 4.0;
	e->cam.fovy = ((float)e->img.height / (float)e->img.width) * e->cam.fovx;
	e->cam.viewplane.width = 0.5;
	e->cam.viewplane.height = 0.35;
	e->cam.viewplane.distance = 1.0;
	e->cam.right = vec3_create(-1.0f, 0.0f, 0.0f);
	e->cam.up = vec3_create(0.0f, 1.0f, 0.0f);
	return (camera_update_viewplane(e));
}
