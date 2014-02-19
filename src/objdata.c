/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:33:58 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 01:16:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scene.h"
#include <libft_memory.h>

t_objdata				*objdata_init(struct s_object *object,
									  t_objdata *data, t_objtype type)
{
	if (!data)
		return (data);
	data->sphere = NULL;
	data->plane = NULL;
	data->light = NULL;
	if (type == OT_SPHERE)
	{
		data->sphere = (t_sphere*)ft_memalloc(sizeof(t_sphere));
		if (data->sphere)
			data->sphere->object = object;
	}
	else if (type == OT_PLANE)
	{
		data->plane = (t_plane*)ft_memalloc(sizeof(t_plane));
		if (data->plane)
			data->plane->object = object;
	}
	else if (type == OT_LIGHT)
	{
		data->light = (t_light*)ft_memalloc(sizeof(t_light));
		if (data->light)
			data->light->object = object;
	}
	return (data);
}

t_objdata				*objdata_create(struct s_object *object,
										t_objtype type)
{
	t_objdata			*ret;

	ret = (t_objdata*)ft_memalloc(sizeof(t_objdata));
	return (objdata_init(object, ret, type));
}

void					objdata_destroy(t_objdata **data)
{
	if (data)
		ft_memdel((void**)data);
}
