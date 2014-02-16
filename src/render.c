/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:56:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 08:56:11 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>
#include <time.h>
#include <math.h>

#define MATERIAL_COUNT		1
#define SPHERE_COUNT		1
#define RAY_MAX_DISTANCE	1000.0
#define RAY_STEP			0.1

static t_material		g_material_base = {
	{1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 0.2f, 0.2f, 0.2f},
	{1.0f, 0.3f, 0.3f, 0.3f}, 45.0f
};

static t_material		g_material_light = {
	{1.0f, 1.0f, 1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f},
	{1.0f, 1.0f, 1.0f, 1.0f}, 45.0f
};
static t_light			g_light = {
	{1.0f, 10.0f, 1.0f}, {0.0f, 0.0f, 0.0f}, LT_POINT, &g_material_light
};

static t_sphere			g_spheres[SPHERE_COUNT] = {
	{1.0f, {0.0f, 0.5f, 0.0f}, &g_material_base}
};

t_vec3					get_viewplane_pixel(t_vec2 pixel, t_engine *e)
{
	t_vec3				ret;
	t_real				xindent;
	t_real				yindent;

	xindent = e->cam.viewplane.width / (float)e->img.width;
	yindent = e->cam.viewplane.height / (float)e->img.height;
	ret = vec3_sub(
		vec3_add(e->cam.viewplane.position,
				 vec3_scale(vec3_scale(e->cam.right, xindent), pixel.x)),
		vec3_scale(vec3_scale(e->cam.up, yindent), pixel.y));
	return (ret);
}

int						check_intersects(t_engine *e, t_ray_result *res)
{
	int					i;
	t_sphere			*cur;
	t_vec3				p;

	if (!e)
		return (0);
	i = 0;
	p = vec3_add(res->ray.origin,
				 vec3_scale(res->ray.direction, res->distance));
	while (i < SPHERE_COUNT)
	{
		cur = &g_spheres[i];
		if (collision_test_sphere(res, cur))
		{
			res->hit = 1;
			res->data = (void*)cur;
			return (1);
		}
		i++;
	}
	return (0);
}

t_ray_result			shoot_ray(t_engine *e, t_ray ray)
{
	t_ray_result		res;

	res.hit = 0;
	res.ray = ray;
	res.distance = 0.0;
	vec3_norm(&res.ray.direction);
/*	while (res.distance < RAY_MAX_DISTANCE)
	{
*/
		if (check_intersects(e, &res))
			res.hit = 1;
/*		res.distance += RAY_STEP;
		if (res.hit)
			break ;
	}
*/	return (res);
}
static clock_t tbegin, tend;
static double time_spent;

void					progress_status(t_engine *e,
										float progress,
										float telapsed)
{
	ft_printf("\r[render:%4ix%4i - %i obj(s)]\t%2i %% - %2i seconds.",
			  e->img.width, e->img.height, SPHERE_COUNT,
			  (int)progress,
			  (int)telapsed);
}

typedef struct			s_renderer
{
	t_vec2				pixel;
	t_ray_result		result;
	t_engine			*engine;
}						t_renderer;

t_renderer				*renderer_init(t_renderer *r, t_engine *e)
{
	if (r)
	{
		r->engine = e;
		r->pixel = vec2_create(0.0f, 0.0f);
		r->result = ray_result_create(0,
									  ray_create(e->cam.position,
												 vec3_sub(
													 get_viewplane_pixel(
														 r->pixel,
														 e),
													 e->cam.position)),
									  0.0f,
									  NULL);
	}
	return (r);
}

t_renderer				*renderer_update(t_renderer *r)
{
	t_vec3				vp;
	t_ray				ray;
	int					col;

	if (!r)
		return (r);
	vp = get_viewplane_pixel(renderer.pixel, r->engine);
	ray.origin = r->engine->cam.position;
	ray.direction = vec3_sub(vp, e->cam.position);
	r->result = shoot_ray(e, ray);
	col = color_hex(color_add(renderer_pass_ambient(r),
							  renderer_pass_diffuse(r));
	image_set_pixel(e, v.x, v.y, col);
	return (r);
}

int						render_image(t_engine *e)
{
	t_renderer			renderer;
	t_vec3				tmp;

	renderer_init(&renderer, e);
	e->img.data = mlx_get_data_addr(e->img.ptr,
									&e->img.bpp,
									&e->img.size_line,
									&e->img.endian);
	progress_status(e, 0.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	tbegin = clock();
	while (renderer.pixel.y < (t_real)e->img.height)
	{
		renderer.pixel.x = 0.0f;
		progress_status(e, ((float)v.y / (float)e->img.height) * 100.0f,
						(clock() - tbegin) / CLOCKS_PER_SEC);
		while (renderer.pixel.x < (t_real)e->img.width)
		{
			renderer_update(&renderer);
			v.x++;
		}
		v.y++;
	}
	progress_status(e, 100.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	ft_printf("\n[render:%4ix%4i - %i obj(s)]:\t%i %% - "
			  "uploading to video memory: ",
			  e->img.width, e->img.height, SPHERE_COUNT);
	mlx_put_image_to_window(e->core, e->win, e->img.ptr, 0, 0);
	printf("done\n");
	return (1);
}
