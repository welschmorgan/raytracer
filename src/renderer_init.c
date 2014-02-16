/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:54:09 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 11:05:05 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdlib.h>

#define MATERIAL_COUNT		1
#define SPHERE_COUNT		1
#define LIGHT_COUNT			1
#define RAY_MAX_DISTANCE	1000.0
#define RAY_STEP			0.1

static t_material		g_material_base = {
	{1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 0.2f, 0.2f, 0.2f},
	{1.0f, 0.3f, 0.3f, 0.3f}, 45.0f
};

static t_material		g_material_light = {
	{1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f},
	{1.0f, 1.0f, 1.0f, 1.0f}, 45.0f
};

static t_light			g_lights[LIGHT_COUNT] = {
	{{1.0f, 10.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, LT_POINT, &g_material_light}
};

static t_sphere			g_spheres[SPHERE_COUNT] = {
	{1.0f, {0.0f, 0.5f, 0.0f}, &g_material_base}
};

t_renderer				*renderer_init(t_renderer *r, t_engine *e)
{
	if (r)
	{
		r->engine = e;
		r->pixel = vec2_create(0.0f, 0.0f);
		r->result = ray_result_create(0,
									  ray_create(e->cam.position,
												 vec3_sub(
													 camera_viewplane_point(
														 e,
														 r->pixel),
													 e->cam.position)),
									  0.0f,
									  NULL);
		r->lights = g_lights;
		r->nlights = LIGHT_COUNT;
		r->objects = g_spheres;
		r->nobjects = SPHERE_COUNT;
		e->img.data = mlx_get_data_addr(e->img.ptr,
										&e->img.bpp,
										&e->img.size_line,
										&e->img.endian);
	}
	return (r);
}
