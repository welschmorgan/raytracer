/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:28:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:02:05 by mwelsch          ###   ########.fr       */
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
	ret.z = -1.0f;
	return (ret);
}

void					camera_lookat(t_engine *e, t_vec3 target)
{
	e->cam.direction = vec3_sub(target, e->cam.position);
}

t_camera				*camera_init(t_engine *e, t_vec3 pos, t_vec3 lookat)
{
	if (!e)
		return (NULL);
	e->cam.position = pos;
	e->cam.direction = vec3_sub(lookat, pos);
	e->cam.fovx = PI / 4;
	e->cam.fovy = (e->img.height / e->img.width) * e->cam.fovx;
	return (&e->cam);
}
