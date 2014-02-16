/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_shoot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 21:35:47 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 21:35:57 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_ray_result			renderer_shoot_planes(t_renderer *r, t_ray *ray)
{
	int					i;
	t_ray_result		res;

	res.hit = 0;
	res.ray = *ray;
	res.distance = 0.0;
	vec3_norm(&res.ray.direction);
	if (!r)
		return (res);
	i = 0;
	while (i < r->engine->scene.nspheres)
	{
		if (collision_test_sphere(&res, &r->engine->scene.spheres[i]))
		{
			res.hit = 1;
			res.data = (void*)&r->engine->scene.spheres[i];
			break ;
		}
		i++;
	}
	return (res);
}

t_ray_result			renderer_shoot_spheres(t_renderer *r, t_ray *ray)
{
	int					i;
	t_ray_result		res;

	res.hit = 0;
	res.ray = *ray;
	res.distance = 0.0;
	vec3_norm(&res.ray.direction);
	if (!r)
		return (res);
	i = 0;
	while (i < r->engine->scene.nplanes)
	{
		if (collision_test_plane(&res, &r->engine->scene.planes[i]))
		{
			res.hit = 2;
			res.data = (void*)&r->engine->scene.planes[i];
			break ;
		}
		i++;
	}
	return (res);
}

t_ray_result			renderer_shoot(t_renderer *r, t_ray ray)
{
	t_ray_result		res;

	res = renderer_shoot_planes(r, &ray);
	if (!res.hit)
		res = renderer_shoot_spheres(r, &ray);
	return (res);
}
