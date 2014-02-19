/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:34:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 14:40:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <libft_memory.h>
#include <libft_dlist.h>
#include <libft_printf.h>
#include <libft_string.h>

#define SPHERE_COUNT		1
#define LIGHT_COUNT			1
#define PLANE_COUNT			1

void					scene_clear(t_scene *scn)
{
	if (scn)
	{
		if (scn->objects)
			ft_dlist_clear(scn->objects, scene_object_destroy);
		if (scn->materials)
			ft_dlist_clear(scn->materials, scene_material_destroy);
		if (scn->lights)
			ft_dlist_clear(scn->lights, scene_light_destroy);
	}
}

t_object				*scene_object_get(t_scene *s, char *name)
{
	t_dnode				*cur;
	t_object			*o;

	cur = s->objects->tail;
	while (cur)
	{
		o = (t_object*)cur->data;
		if (o && ft_strequ(o->name, name))
			return (o);
		cur = cur->next;
	}
	cur = s->lights->tail;
	while (cur)
	{
		o = (t_object*)cur->data;
		if (o && ft_strequ(o->name, name))
			return (o);
		cur = cur->next;
	}
	return (NULL);
}

t_object				*scene_create_object(t_scene *scn, char *name,
											 t_objtype type, t_material *mat)
{
	return (scene_object_add(scn, object_create(name, type, mat)));
}

t_sphere				*scene_create_sphere(t_scene *scn, char *name,
											 t_material *mat)
{
	t_object			*obj;

	ft_printf("[create] sphere '%s'\n", name);
	obj = scene_create_object(scn, name, OT_SPHERE, mat);
	return (obj ? obj->data->sphere : NULL);
}

t_plane					*scene_create_plane(t_scene *scn, char *name,
											t_material *mat)
{
	t_object			*obj;

	ft_printf("[create] plane '%s'\n", name);
	obj = scene_create_object(scn, name, OT_PLANE, mat);
	return (obj ? obj->data->plane : NULL);
}

t_light					*scene_create_light(t_scene *scn,
											char *name,
											t_ltype type,
											t_material *mat)
{
	t_object			*o;
	t_light				*l;

	ft_printf("[create] light '%s'\n");
	o = scene_create_object(scn, name, OT_LIGHT, mat);
	l = o->data->light;
	l->position = vec3_zero();
	l->direction = vec3_zero();
	l->type = type;
	return (l);
}

t_material				*scene_create_material(t_scene *scn, char *name)
{
	t_material			*m;

	ft_printf("[create] material '%s'\n", name);
	m = material_new(name);
	if (m)
		ft_dlist_push_back(scn->materials,
						   ft_dnode_new(m, sizeof(*m), NF_DESTROY_ALL));
	return (m);
}

t_object				*scene_object_add(t_scene *scn, t_object *obj)
{
	if (!scn)
	{
		if (obj)
			object_destroy(&obj);
		return (obj);
	}
	if (obj->type == OT_LIGHT)
		ft_dlist_push_back(scn->lights,
						   ft_dnode_new(obj,
										sizeof(t_object),
										NF_DESTROY_ALL));
	else
		ft_dlist_push_back(scn->objects,
						   ft_dnode_new(obj,
										sizeof(t_object),
										NF_DESTROY_ALL));
	return (obj);
}

t_scene					*scene_create(struct s_renderer *r, char const *name)
{
	t_scene				*s;

	ft_printf("[create] scene '%s'\n", name);
	s = (t_scene*)ft_memalloc(sizeof(t_scene));
	return (scene_init(s, r, name));
}

t_scene					*scene_init(t_scene *scn, struct s_renderer *r,
									char const *name)
{
	if (scn)
	{
		ft_strncpy(scn->name, name, SCENE_NAME_LENGTH);
		scn->objects = ft_dlist_new();
		scn->renderer = r;
		scn->materials = ft_dlist_new();
		scn->lights = ft_dlist_new();
		scn->ambient = color_create(0.0f, 0.0f, 0.0f, 1.0f);
	}
	return (scn);
}
