/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:18:03 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 03:43:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <stddef.h>

t_real					renderer_light_compute_angle(t_normal surf_normal,
													 t_vec3 contact_pt,
													 t_light *l)
{
	t_vec3				ldir;

	if (!l)
		return (0.0f);
	ldir = vec3_sub(contact_pt, l->position);
	vec3_norm(&ldir);
	return (vec3_dot(surf_normal, vec3_scale(ldir, -1.0f)));
}

t_color					renderer_light_compute(t_renderer *r, t_light *l)
{
	t_object			*obj;
	t_real				angle;
	t_material			*material;
	t_ray_contact		*contact;

	if (r->result.hit)
	{
		obj = ((t_object*)r->result.contact.data);
		contact = &r->result.contact;
		angle = 0.0f;
		if (obj->type == OT_SPHERE)
			angle = renderer_light_compute_angle(sphere_normal(
													 obj->data->sphere,
													 contact->point),
												 contact->point,
								l);
		else if (obj->type == OT_PLANE)
			angle = renderer_light_compute_angle(obj->data->plane->normal,
												 contact->point,
												 l);
		if (angle > 0)
		{
			if (obj->type == OT_PLANE)
				material = obj->data->plane->material;
			else if (obj->type == OT_SPHERE)
				material = obj->data->sphere->material;
			return (color_scale(color_mul(material->diffuse,
										  l->material->diffuse),
								angle));
		}
	}
	return (color_create(0.0f, 0.0f, 0.0f, 0.0f));
}

t_color					renderer_light_compute_list(t_renderer *r, t_dlist *lst)
{
	t_color				c;
	t_dnode				*l;

	c = color_create(0.0f, 0.0f, 0.0f, 1.0f);
	if (!lst)
		return (c);
	l = lst->tail;
	while (l && l != lst->head)
	{
		c = color_add(c, renderer_light_compute(r, ((t_light*)l->data)));
		l = l->next;
	}
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
	ray.origin = r->engine->cam->position;
	ray.direction = vec3_sub(vp, r->engine->cam->position);
	r->result = renderer_shoot(r, ray);
	col = color_hex(renderer_light_compute_list(r, r->engine->scene->lights));
	image_set_pixel(r->engine, r->pixel.x, r->pixel.y, col);
	return (r);
}
