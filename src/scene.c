/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:34:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 14:56:52 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#define SPHERE_COUNT		1
#define LIGHT_COUNT			1
#define PLANE_COUNT			1

#define RAY_MAX_DISTANCE	1000.0
#define RAY_STEP			0.1

static t_material		g_material_red = {
	{1.0f, 1.0f, 1.0f, 1.0f},
	{1.0f, 0.1f, 0.1f, 1.0f},
	{0.3f, 0.3f, 0.3f, 1.0f}, 45.0f
};

static t_material		g_material_green = {
	{1.0f, 1.0f, 1.0f, 1.0f},
	{0.1f, 1.0f, 0.1f, 1.0f},
	{0.3f, 0.3f, 0.3f, 1.0f}, 45.0f
};

/*static t_material		g_material_blue = {
	{1.0f, 1.0f, 1.0f, 1.0f},
	{0.1f, 0.1f, 1.0f, 1.0f},
	{0.3f, 0.3f, 0.3f, 1.0f}, 45.0f
	};*/

static t_material		g_material_light = {
	{1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f},
	{1.0f, 1.0f, 1.0f, 1.0f}, 45.0f
};

static t_light			g_lights[LIGHT_COUNT] = {
	{{10.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, LT_POINT, &g_material_light}
};

static t_plane			g_planes[PLANE_COUNT] = {
	{{0.0f, 1.0f, 0.0f}, {10.0f, -0.5f, 10.0f}, &g_material_red}
};

static t_sphere			g_spheres[SPHERE_COUNT] = {
	{1.0f, {0.0f, 0.5f, 0.0f}, &g_material_green}
};

t_scene					*scene_init(t_scene *scn, struct s_renderer *r)
{
	if (scn)
	{
		scn->spheres = g_spheres;
		scn->lights = g_lights;
		scn->planes = g_planes;
		scn->nspheres = SPHERE_COUNT;
		scn->nlights = LIGHT_COUNT;
		scn->nplanes = PLANE_COUNT;
		scn->renderer = r;
	}
	return (scn);
}
