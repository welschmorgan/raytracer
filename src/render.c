/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:56:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:21:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>

#define SPHERE_COUNT	2
#define RAY_MAX_DISTANCE 1000.0f
#define RAY_STEP		0.1f

static t_sphere			g_spheres[SPHERE_COUNT + 1] = {
	{1.0f, {0.0f, 0.0f, 0.0f}},
	{3.0f, {4.0f, 1.0f, 0.0f}},
	{0.0f, {0.0f, 0.0f, 0.0f}}
};

int						check_intersects(t_engine *e, t_vec3 p)
{
	int					i;
	t_sphere			*cur;

	if (!e)
		return (0);
	i = 0;
	while (i < SPHERE_COUNT)
	{
		cur = &g_spheres[i];
		if (collision_test_sphere(p, *cur))
		{
			ft_printf("Intersected\n");
		}
		i++;
	}
	return (1);
}

t_ray_result			shoot_ray(t_engine *e, t_ray ray)
{
	t_ray_result		res;

	res.hit = 0;
	res.ray = ray;
	res.distance = 0.0;
#ifdef _DEBUG
	printf("Shooting [%f,%f] -> [%f, %f]\n",
			  ray.origin.x, ray.origin.y,
			  ray.direction.x, ray.direction.y);
#endif
	while (res.distance < RAY_MAX_DISTANCE)
	{
		if (check_intersects(e, vec3_add(res.ray.origin, vec3_scale(
											 res.ray.direction,
											 res.distance))))
		{
			res.hit = 1;
			return (res);
		}
		res.distance += RAY_STEP;
	}
	return (res);
}
int						render_image(t_engine *e)
{
	t_vec2				v;
	t_ray				ray;
	t_vec3				tmp;
	t_ray_result		res;

	v.y = 0.0f;
	e->img.data = mlx_get_data_addr(e->img.ptr,
									&e->img.bpp,
									&e->img.size_line,
									&e->img.endian);
	ft_printf("rendering image\n");
	ray.origin = e->cam.position;
	while (v.y < (t_real)e->img.height)
	{
		v.x = 0.0f;
		while (v.x < (t_real)e->img.width)
		{
			tmp = viewplane_point(v, e);
			ray.direction = vec3_sub(tmp, e->cam.position);
			res = shoot_ray(e, ray);
			image_set_pixel(e, v.x, v.y, color_hex(color_ray(&res)));
			v.x++;
		}
		v.y++;
	}
	mlx_put_image_to_window(e->core, e->win, e->img.ptr, 0, 0);
	return (1);
}
