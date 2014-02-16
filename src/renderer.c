/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:18:03 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:58:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <stddef.h>

t_ray_result			renderer_shoot(t_renderer *r, t_ray ray)
{
	int					i;
	t_sphere			*cur;
	t_ray_result		res;

	res.hit = 0;
	res.ray = ray;
	res.distance = 0.0;
	vec3_norm(&res.ray.direction);
	if (!r)
		return (res);
	i = 0;
	while (i < r->nobjects)
	{
		cur = &r->objects[i];
		if (collision_test_sphere(&res, cur))
		{
			res.hit = 1;
			res.data = (void*)cur;
			break ;
		}
		i++;
	}
	return (res);
}

t_color					renderer_pass_ambient(t_renderer *r)
{
	t_color				c;
	t_sphere			*sphere;

	(void)r;
	c = color_create(0.1f, 0.1f, 0.1f, 1.0f);
	if (r->result.hit)
	{
		sphere = (t_sphere*)r->result.data;
		if (sphere)
			c = sphere->material->ambient;
	}
	else
		c.b = 1.0f;
	return (c);
}

t_color					light_at(t_ray_result *res, t_light *l)
{
	t_vec3				lightv;
	t_vec3				contact;
	t_color				c;

	contact = vec3_add(res->ray.origin,
					   vec3_scale(res->ray.direction,
								  res->distance));
	lightv = vec3_sub(contact, l->position);
	c = color_create(0.0f, 0.0f, 0.0f, 0.0f);
	return (c);
}

t_color					renderer_pass_diffuse(t_renderer *r)
{
	t_color				c;

	(void)r;
	c = color_create(0.0f, 0.0f, 0.0f, 1.0f);
	return (c);
}

t_renderer				*renderer_update(t_renderer *r)
{
	t_vec3				vp;
	t_ray				ray;
	int					col;

	if (!r)
		return (r);
	vp = camera_viewplane_point(r->engine, r->pixel);
	ray.origin = r->engine->cam.position;
	ray.direction = vec3_sub(vp, r->engine->cam.position);
	r->result = renderer_shoot(r, ray);
	col = color_hex(color_add(renderer_pass_ambient(r),
							  renderer_pass_diffuse(r)));
	image_set_pixel(r->engine, r->pixel.x, r->pixel.y, col);
	return (r);
}
