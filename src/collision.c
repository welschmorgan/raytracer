/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:14:01 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:07:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <libft_string.h>
#include <libft_printf.h>
#include <libft_converters.h>
#include <libmath_utils.h>
#include "raytracer.h"

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
	r->hit = OT_SPHERE;
	r->contact.point = vec3_add(r->ray.origin,
								vec3_scale(r->ray.direction, r->distance));
	return (1);
}

int						collision_test_plane(t_ray_result *result,
											 t_plane *plane)
{
	t_vec3				opp;
	t_real				dv;

	opp = vec3_sub(result->ray.origin, plane->point);
	dv = vec3_dot(plane->normal, result->ray.direction);
	if (!dv)
		return (0);
	result->distance = -vec3_dot(plane->normal, opp) / dv;
	if (result->distance < 0)
		return (0);
	result->hit = OT_PLANE;
	result->contact.point = vec3_add(result->ray.origin,
									 vec3_scale(result->ray.direction,
												result->distance));
	return (1);
}

int						collision_test_object(t_renderer *r,
											  t_ray_result *res,
											  t_object *obj)
{
	if (!r || !res || !obj)
		return (0);
	res->hit = OT_NONE;
	res->contact.data = obj;
	if (obj->type == OT_SPHERE)
		return (collision_test_sphere(res, obj->data->sphere));
	else if (obj->type == OT_PLANE)
		return (collision_test_plane(res, obj->data->plane));
	return (0);
}
