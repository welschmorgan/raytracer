/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:14:01 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:52:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <libft_string.h>
#include <libft_printf.h>
#include <libft_converters.h>
#include "raytracer.h"

static t_real			collision_test_sphere_a(t_vec3 *r_dir)
{
	return ((r_dir->x * r_dir->x)
			+ (r_dir->y * r_dir->y)
			+ (r_dir->z * r_dir->z));
}

static t_real			collision_test_sphere_b(t_ray *ray, t_vec3 *sphere_pos)
{
	return (2.0 * (ray->direction.x * (ray->origin.x - sphere_pos->x)
				   + ray->direction.y * (ray->origin.y - sphere_pos->y)
				   + ray->direction.z * (ray->origin.z - sphere_pos->z)));
}

static t_real			collision_test_sphere_c(t_ray *ray, t_sphere *sphere)
{
	return (((ray->origin.x - sphere->position.x)
			 * (ray->origin.x - sphere->position.x))
			+ ((ray->origin.y - sphere->position.y)
			   * (ray->origin.y - sphere->position.y))
			+ ((ray->origin.z - sphere->position.z)
			   * (ray->origin.z - sphere->position.z))
			- sphere->radius * sphere->radius);
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

	det = (b * b) - (4 * a * c);
	if (!det)
		r->distance = -(b / 2 * a);
	else if (det > 0)
		r->distance = FT_MIN((-b - sqrt(det)) / (2 * a),
							 (-b + sqrt(det)) / (2 * a));
	else
		return (0);
	return (1);
}
