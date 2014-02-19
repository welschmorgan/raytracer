/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:54:09 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 12:10:03 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_memory.h>
#include "raytracer.h"
#include <libft_printf.h>

t_renderer				*renderer_new(t_engine *e)
{
	return (renderer_init((t_renderer*)ft_memalloc(sizeof(t_renderer)), e));
}

t_renderer				*renderer_init(t_renderer *r, t_engine *e)
{
	if (r)
	{
#ifdef _DEBUG
		ft_printf("Initialising renderer\n");
#endif
		r->engine = e;
		r->pixel = vec2_create(0.0f, 0.0f);
		r->result = ray_result_create(0,
									  ray_create(e->cam->position,
												 vec3_sub(
													 camera_viewplane_point(
														 e,
														 r->pixel),
													 e->cam->position)),
									  0.0f,
									  NULL);
		if (e->scene)
			scene_init(e->scene, r, "main scene");
		e->img->data = mlx_get_data_addr(e->img->ptr,
										 &e->img->bpp,
										 &e->img->size_line,
										 &e->img->endian);
	}
	return (r);
}
