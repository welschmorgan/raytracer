/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:54:09 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 14:30:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdlib.h>

t_renderer				*renderer_init(t_renderer *r, t_engine *e)
{
	if (r)
	{
		r->engine = e;
		r->pixel = vec2_create(0.0f, 0.0f);
		r->result = ray_result_create(0,
									  ray_create(e->cam.position,
												 vec3_sub(
													 camera_viewplane_point(
														 e,
														 r->pixel),
													 e->cam.position)),
									  0.0f,
									  NULL);
		scene_init(&e->scene, r);
		e->img.data = mlx_get_data_addr(e->img.ptr,
										&e->img.bpp,
										&e->img.size_line,
										&e->img.endian);
	}
	return (r);
}
