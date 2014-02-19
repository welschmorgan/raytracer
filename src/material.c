/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 01:55:30 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 02:53:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "material.h"
#include <libft_string.h>
#include <libft_memory.h>

t_material				*material_new(char *name)
{
	t_material			*m;

	m = (t_material*)ft_memalloc(sizeof(t_material));
	return (material_init(m, name));
}
t_material				*material_init(t_material *m, char *name)
{
	if (m)
	{
		ft_strncpy(m->name, name, MATERIAL_NAME_LENGTH);
		m->specular = color_create(0.0f, 0.0f, 0.0f, 1.0f);
		m->diffuse = color_create(1.0f, 1.0f, 1.0f, 1.0f);
		m->ambient = color_create(0.0f, 0.0f, 0.0f, 1.0f);
		m->shininess = 1.0f;
	}
	return (m);
}

void					material_destroy(t_material **mat)
{
	if (mat)
		ft_memdel((void**)mat);
}
