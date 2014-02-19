/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:18:03 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:54:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <stdio.h>
#include <libft_printf.h>



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
	renderer_shoot(r, ray);
	col = color_hex(renderer_light_compute_list(r, r->engine->scene->lights));
	image_set_pixel(r->engine, r->pixel.x, r->pixel.y, col);
	return (r);
}
