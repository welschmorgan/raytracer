/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:34:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 02:20:48 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <libft_memory.h>
#include <libft_dlist.h>

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
t_object				*scene_create_object(t_scene *scn, char *name,
											 t_objtype type, t_material *mat)
{
	return (scene_object_add(scn, object_create(name, type, mat)));
}

t_sphere				*scene_create_sphere(t_scene *scn, char *name,
											 t_material *mat)
{
	t_object			*obj;

	obj = scene_create_object(scn, name, OT_SPHERE, mat);
	return (obj ? obj->data->sphere : NULL);
}

t_plane					*scene_create_plane(t_scene *scn, char *name,
											t_material *mat)
{
	t_object			*obj;

	obj = scene_create_object(scn, name, OT_PLANE, mat);
	return (obj ? obj->data->plane : NULL);
}

t_light					*scene_create_light(t_scene *scn,
											t_ltype type,
											t_vec3 pos,
											t_material *mat)
{
	t_light				*l;

	l = (t_light*)ft_memalloc(sizeof(t_light));
	if (!l)
		return (l);
	l->position = pos;
	l->direction = vec3_create(0.0f, 0.0f, 0.0f);
	l->type = type;
	l->material = mat;
	ft_dlist_push_back(scn->lights,
					   ft_dnode_new(l, sizeof(*l), NF_DESTROY_ALL));
	return (l);
}

t_material				*scene_create_material(t_scene *scn, char *name)
{
	t_material			*m;

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
	ft_dlist_push_back(scn->objects,
					   ft_dnode_new(obj,
									sizeof(t_object),
									NF_DESTROY_ALL));
	return (obj);
}

t_scene					*scene_create(struct s_renderer *r)
{
	t_scene				*s;

	s = (t_scene*)ft_memalloc(sizeof(t_scene));
	return (scene_init(s, r));
}

t_scene					*scene_init(t_scene *scn, struct s_renderer *r)
{
	if (scn)
	{
		scn->objects = ft_dlist_new();
		scn->renderer = r;
		scn->materials = ft_dlist_new();
		scn->lights = ft_dlist_new();
	}
	return (scn);
}
