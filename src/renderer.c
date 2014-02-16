/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:18:03 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 21:35:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <stddef.h>

t_color					renderer_pass_ambient(t_renderer *r)
{
	t_color				c;
	t_sphere			*sphere;
	t_plane				*plane;

	(void)r;
	c = color_create(0.1f, 0.1f, 0.1f, 1.0f);
	if (r->result.hit)
	{
		if (r->result.hit == 2)
		{
			plane = (t_plane*)r->result.data;
			c = plane->material->ambient;
		}
		else
		{
			sphere = (t_sphere*)r->result.data;
			c = sphere->material->ambient;
		}
	}
	else
		c.b = 1.0f;
	return (c);
}

t_color					light_at(t_renderer *r, t_light *l)
{
	t_ray				lightr;
	t_vec3				contact;
	t_vec3				contact_n;
	t_color				c;
	t_real				angle;
	t_material			*material;

	c = color_create(0.0f, 0.0f, 0.0f, 0.0f);
	contact = vec3_add(r->result.ray.origin,
					   vec3_scale(r->result.ray.direction,
								  r->result.distance));
	lightr.origin = l->position;
	lightr.direction = vec3_sub(contact, l->position);
	vec3_norm(&lightr.direction);
	if (r->result.hit)
	{
		if (r->result.hit == 2)
			contact_n = ((t_plane*)r->result.data)->normal;
		else
			contact_n = sphere_normal(((t_sphere*)r->result.data), contact);
		angle = vec3_dot(contact_n, vec3_create(-lightr.direction.x,
										-lightr.direction.y,
										-lightr.direction.z));
		if (angle > 0)
		{
			if (r->result.hit == 2)
				material = ((t_plane*)r->result.data)->material;
			else
				material = ((t_sphere*)r->result.data)->material;
			if (material)
				c = color_scale(color_mul(material->diffuse,
										  l->material->diffuse),
								angle);
		}
	}
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
	col = color_hex(light_at(r, r->engine->scene.lights));
/*color_add(renderer_pass_ambient(r),
					  renderer_pass_diffuse(r))*/
	image_set_pixel(r->engine, r->pixel.x, r->pixel.y, col);
	return (r);
}
