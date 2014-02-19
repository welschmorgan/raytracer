/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:28:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 00:26:56 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libmath.h>
#include <math.h>
#include <stddef.h>
#include <libft_memory.h>

t_vec3					camera_viewplane_point(t_engine *e, t_vec2 pixel)
{
	t_vec3				ret;
	t_real				xindent;
	t_real				yindent;

	xindent = e->cam->viewplane.width / (float)e->img->width;
	yindent = e->cam->viewplane.height / (float)e->img->height;
	ret = vec3_sub(
		vec3_add(e->cam->viewplane.position,
				 vec3_scale(vec3_scale(e->cam->right, xindent), pixel.x)),
		vec3_scale(vec3_scale(e->cam->up, yindent), pixel.y));
	return (ret);
}

void					camera_destroy(t_camera **e)
{
	if (e)
		ft_memdel((void**)e);
}

t_camera				*camera_new(struct s_engine *e,
									t_vec3 pos,
									t_vec3 lookat)
{
	t_camera			*cam;

	cam = NULL;
	if (e)
		cam = (t_camera*)ft_memalloc(sizeof(t_camera));
	return (camera_init(cam, e, pos, lookat));
}

void					camera_lookat(t_camera *cam, t_vec3 target)
{
	cam->direction = vec3_sub(target, cam->position);
}

t_camera				*camera_update_viewplane(t_camera *c)
{
	if (!c)
		return (NULL);
	c->viewplane.position
		= vec3_add(c->position, vec3_sub(
					   vec3_add(
						   vec3_scale(c->direction,
									c->viewplane.distance),
						   vec3_scale(c->up,
									  c->viewplane.height * 0.5f)),
					   vec3_scale(c->right,
								  c->viewplane.width * 0.5f)));
	return (c);
}

t_camera				*camera_init(t_camera *cam, struct s_engine *e,
									 t_vec3 pos, t_vec3 lookat)
{
	if (!e || !cam)
		return (NULL);
	cam->position = pos;
	cam->direction = vec3_sub(lookat, pos);
	vec3_norm(&cam->direction);
	cam->engine = e;
	cam->viewplane.camera = cam;
	cam->fovx = PI / 4.0;
	cam->fovy = ((float)e->img->height / (float)e->img->width)
		* cam->fovx;
	cam->viewplane.width = 0.5;
	cam->viewplane.height = 0.35;
	cam->viewplane.distance = 1.0;
	cam->right = vec3_create(-1.0f, 0.0f, 0.0f);
	cam->up = vec3_create(0.0f, 1.0f, 0.0f);
	return (camera_update_viewplane(cam));
}
