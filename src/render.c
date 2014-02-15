/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:56:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 00:05:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>
#include <time.h>

#define MATERIAL_COUNT		1
#define SPHERE_COUNT		1
#define RAY_MAX_DISTANCE	1000.0
#define RAY_STEP			0.1

static t_material		g_material_base = {
	{1.0f, 1.0f, 1.0f, 1.0f},
	{1.0f, 0.2f, 0.2f, 0.2f},
	{1.0f, 0.1f, 0.1f, 0.1f},
	45.0f
};
static t_sphere			g_spheres[SPHERE_COUNT] = {
	{4.0f, {0.0f, 0.5f, -20.0f}, &g_material_base}
};

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
		if (collision_test_sphere(p, *cur))
		{
			res->data = (void*)cur->material;
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
	while (res.distance < RAY_MAX_DISTANCE)
	{
		if (check_intersects(e, &res))
			res.hit = 1;
		res.distance += RAY_STEP;
		if (res.hit)
			break ;
	}
	return (res);
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

int						render_image(t_engine *e)
{
	t_vec2				v;
	t_ray				ray;
	t_vec3				tmp;
	t_ray_result		res;
	float				progress;

	v.y = 0.0f;
	e->img.data = mlx_get_data_addr(e->img.ptr,
									&e->img.bpp,
									&e->img.size_line,
									&e->img.endian);
	ray.origin = e->cam.position;
	progress_status(e, 0.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	tbegin = clock();
	while (v.y < (t_real)e->img.height)
	{
		v.x = 0.0f;
		time_spent = (double)(clock() - tbegin) / CLOCKS_PER_SEC;
		progress = v.y / (float)e->img.height;
		progress_status(e, progress * 100.0f,
						(clock() - tbegin) / CLOCKS_PER_SEC);
		while (v.x < (t_real)e->img.width)
		{
			tmp = viewplane_point(v, e);
			ray.direction = vec3_sub(tmp, e->cam.position);
			res = shoot_ray(e, ray);
			if (res.hit)
			{
				ft_printf("[%i,%i]: Hit\n", (int)v.x, (int)v.y);
			}
			image_set_pixel(e, v.x, v.y,
							color_ray(&res, (t_material*)res.data));
			v.x++;
		}
		v.y++;
	}
	tend = clock();
	time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
	progress_status(e, 100.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	ft_printf("\n[render:%4ix%4i - %i obj(s)]:\tuploading to video memory: ",
			  e->img.width, e->img.height, SPHERE_COUNT);
	mlx_put_image_to_window(e->core, e->win, e->img.ptr, 0, 0);
	printf("done\n");
	return (1);
}
