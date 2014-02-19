/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:02:48 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:44:20 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scene.h"
#include <libft_string.h>
#include <libft_memory.h>
#include <libft_printf.h>

char					*objtype_type2str(t_objtype t)
{
	static char			buf[20];

	ft_strncpy(buf, "unknown", 20);
	if (t == OT_SPHERE)
		ft_strncpy(buf, "sphere", 20);
	else if (t == OT_PLANE)
		ft_strncpy(buf, "plane", 20);
	else if (t == OT_LIGHT)
		ft_strncpy(buf, "light", 20);
	else
		ft_strncpy(buf, "none", 20);
	return (buf);
}

t_objtype				objtype_str2type(char * str)
{
	if (!str)
		return (OT_COUNT);
	if (ft_strequ("sphere", ft_strtolower(str)))
		return (OT_SPHERE);
	else if (ft_strequ("plane", ft_strtolower(str)))
		return (OT_PLANE);
	else if (ft_strequ("light", ft_strtolower(str)))
		return (OT_LIGHT);
	return (OT_NONE);
}

t_normal				object_normal(t_object *o, t_vec3 contact)
{
	t_normal			ret;

	ret = vec3_zero();
	if (!o)
		return (ret);
	if (o->type == OT_SPHERE)
		ret = vec3_sub(contact, o->data->sphere->position);
	else if (o->type == OT_PLANE)
		ret = o->data->plane->normal;
	vec3_norm(&ret);
	return (ret);
}

t_object				*object_init(t_object *o,
									 const char *name,
									 t_objtype type,
									 t_material *mat)
{
	if (o)
	{
		ft_strncpy(o->name, name, OBJECT_NAME_LENGTH);
		ft_printf("object '%s' material: %s\n", name,
				  mat ? mat->name : "invalid");
		o->type = type;
		o->data = objdata_create(o, type);
		o->material = mat;
	}
	return (o);
}

t_object				*object_create(const char *name,
									   t_objtype type,
									   t_material *mat)
{
	t_object			*ret;

	ft_printf("[create] object '%s'\n", name);
	ret = (t_object*)ft_memalloc(sizeof(t_object));
	return (object_init(ret, name, type, mat));
}

void					object_destroy(t_object **obj)
{
	if (obj && *obj)
	{
		ft_printf("[destroy] object '%s'\n", (*obj)->name);
		objdata_destroy((t_objdata**)&(*obj)->data);
		ft_memdel((void**)obj);
	}
}
