/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 02:26:24 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 12:00:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scene.h"
#include <libft_memory.h>
#include <libft_dlist.h>
#include <libft_printf.h>

void					scene_material_destroy(t_dnode *n)
{
	if (n)
	{
		if (n->flag & NF_DESTROY_DATA)
			ft_memdel((void**)&n->data);
		if (n->flag & NF_DESTROY_NODE)
			ft_memdel((void**)&n);
	}
}

void					scene_light_destroy(t_dnode *n)
{
	if (n)
	{
		if (n->flag & NF_DESTROY_DATA)
			ft_memdel((void**)&n->data);
		if (n->flag & NF_DESTROY_NODE)
			ft_memdel((void**)&n);
	}
}

void					scene_object_destroy(t_dnode *obj)
{
	if (obj)
	{
		if (obj->flag & NF_DESTROY_DATA)
			object_destroy((t_object**)&obj->data);
		if (obj->flag & NF_DESTROY_NODE)
			ft_memdel((void**)&obj);
	}
}

void					scene_destroy(t_scene **scn)
{
	if (scn && *scn)
	{
		ft_printf("[destroy] scene\n");
		scene_clear(*scn);
		ft_dlist_destroy(&(*scn)->objects, scene_object_destroy);
		ft_dlist_destroy(&(*scn)->materials, scene_material_destroy);
		ft_dlist_destroy(&(*scn)->lights, scene_light_destroy);
		ft_memdel((void**)scn);
	}
}
