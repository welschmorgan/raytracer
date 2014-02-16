/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:14:01 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 14:26:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <libft_string.h>
#include <libft_printf.h>
#include <libft_converters.h>
#include <libmath_utils.h>
#include "raytracer.h"

static t_real			collision_test_sphere_a(t_vec3 *r_dir)
{
	return (ft_pow(r_dir->x, 2) + ft_pow(r_dir->y, 2) + ft_pow(r_dir->z, 2));
}

static t_real			collision_test_sphere_b(t_ray *ray, t_vec3 *sphere_pos)
{
	t_vec3				osp;
	t_vec3				dosp;

	osp = vec3_sub(ray->origin, *sphere_pos);
	dosp = vec3_mul(ray->direction, osp);
	return (2.0 * (dosp.x + dosp.y + dosp.z));
}

static t_real			collision_test_sphere_c(t_ray *ray, t_sphere *sphere)
{
	return (ft_pow(ray->origin.x - sphere->position.x, 2)
			+ ft_pow(ray->origin.y - sphere->position.y, 2)
			+ ft_pow(ray->origin.z - sphere->position.z, 2)
			- ft_pow(sphere->radius, 2));
}

int						collision_test_sphere(t_ray_result *r,
											  t_sphere *sphere)
{
	t_real				a;
	t_real				b;
	t_real				c;
	t_real				det;

	a = collision_test_sphere_a(&r->ray.direction);
	b = collision_test_sphere_b(&r->ray, &sphere->position);
	c = collision_test_sphere_c(&r->ray, sphere);

	det = ft_pow(b, 2) - (4 * a * c);
	if (!det)
		r->distance = -(b / 2 * a);
	else if (det > 0)
		r->distance = FT_MIN((-b - sqrt(det)) / (2 * a),
							 (-b + sqrt(det)) / (2 * a));
	else
		return (0);
	return (1);
}

int						collision_test_plane(t_ray_result *result,
											 t_plane *plane)
{
	t_vec3				opp;
	t_real				t;
	t_real				dv;

	opp = vec3_sub(result->ray.origin, plane->point);
	dv = vec3_dot(plane->normal, result->ray.direction);
	if (!dv)
		return (0);
	t = -vec3_dot(plane->normal, opp) / dv;
	if (t < 0)
		return (0);
	result->distance = t;
	return (1);
}
