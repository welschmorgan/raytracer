/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:14:01 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/15 22:55:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_string.h>
#include <libft_printf.h>
#include <libft_converters.h>

int						collision_test_sphere(t_ray_result *r,
											t_sphere *sphere)
{
	t_real				a;
	t_real				b;
	t_real				c;
	t_real				det;

	a = (r->ray.direction.x * r->ray.direction.x)
		+ (r->ray.direction.y * r->ray.direction.y)
		+ (r->ray.direction.z * r->ray.direction.z);
	b = 2.0 * (r->ray.direction.x * (r->ray.origin.x - sphere->position.x)
			 + r->ray.direction.y * (r->ray.origin.y - sphere->position.y)
			 + r->ray.direction.z * (r->ray.origin.z - sphere->position.z));
	c = ((r->ray.origin.x - sphere->position.x)
		 * (r->ray.origin.x - sphere->position.x))
		+ ((r->ray.origin.y - sphere->position.y)
		   * (r->ray.origin.y - sphere->position.y))
		+ ((r->ray.origin.z - sphere->position.z)
		   * (r->ray.origin.z - sphere->position.z))
		- sphere->radius * sphere->radius;
	det = (b * b) - (4 * a * c);
	if (!det)
		r->distance = -(b / 2 * a);
	else if (det > 0)
	{
		r->distance = FT_MIN((-b - sqrt(det)) / (2 * a),
							 (-b + sqrt(det)) / (2 * a));
	}
	else
		return (0);
	return (1);
}


int					collision_test_point(t_vec3 p1, t_vec3 p2, t_real radius)
{
	t_sphere		s;

	s.position = p2;
	s.radius = radius;
	return (collision_test_sphere(p1, s));
}
