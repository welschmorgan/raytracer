/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_lighting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 15:45:41 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 18:44:40 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>
#include <math.h>

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

t_color					color_pow(t_color c, t_uint pow)
{
	t_color				ret;

	ret = c;
	while (pow && --pow)
		ret = color_mul(ret, c);
	return (ret);
}

static t_color			final_lighting(t_material *surf, t_material *light,
									   t_real angle, t_real refl)
{
	t_material			final;
	t_color				ret;

	ret = color_create(0.0, 0.0, 0.0, 0.0);
	if (!surf || !light)
		return (ret);
	final.diffuse = color_scale(color_mul(
									surf->diffuse,
									light->diffuse),
								angle);
	final.specular = color_scale(color_mul(light->specular, surf->specular),
							   refl);
	return (color_mul(color_add(final.diffuse, surf->ambient), final.specular));
}

t_real					renderer_light_compute_reflection(t_renderer *r,
														  t_light *l)
{
	t_vec3				refl;
	t_vec3				lightv;
	t_vec3				eyev;
	t_color				c;

	c = color_create(1.0, 1.0, 1.0, 1.0);
	if (!r || !l)
		return (0.0f);
	eyev = vec3_sub(r->engine->cam->position, r->result.contact.point);
	lightv = vec3_sub(r->result.contact.point, l->position);
	refl = vec3_reflect(lightv, object_normal((t_object*)r->result.contact.data,
											  r->result.contact.point));
	return (vec3_dot(eyev, refl));
}

t_color					renderer_light_compute(t_renderer *r, t_light *l)
{
	t_object			*obj;
	t_real				angle;
	t_material			*material;
	t_ray_contact		*contact;
	t_real				reflection;


	if (r->result.hit)
	{
		obj = ((t_object*)r->result.contact.data);
		contact = &r->result.contact;
		angle = renderer_light_compute_angle(object_normal(obj, contact->point),
											 contact->point,
											 l);
		reflection = renderer_light_compute_reflection(r, l);
		if (angle > 0)
		{
			material = obj->material;
			if (material)
				return (final_lighting(material, l->object->material,
									   angle, reflection));
			else
				ft_printf("[info] missing material for object '%s' (%s)\n",
						  obj->name, objtype_type2str(obj->type));
		}
	}
	return (r->engine->scene->ambient);
}

t_color					renderer_light_compute_list(t_renderer *r, t_dlist *lst)
{
	t_color				c;
	t_dnode				*l;
	t_objdata			*data;

	c = color_create(0.0f, 0.0f, 0.0f, 1.0f);
	if (!lst)
		return (c);
	l = lst->tail;
	while (l)
	{
		data = l->data ? ((t_object*)l->data)->data : NULL;
		if (data)
			c = color_add(c, renderer_light_compute(r, data->light));
		l = l->next;
	}
	return (c);
}
