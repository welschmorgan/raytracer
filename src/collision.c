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

int					collision_test_sphere(t_vec3 p, t_sphere sphere)
{
	int					v[3];

	v[VEC_X] = p.x >= sphere.position.x
		&& p.x <= (sphere.position.x + sphere.radius);
	v[VEC_Y] = p.y >= sphere.position.y
		&& p.y <= (sphere.position.y + sphere.radius);
	v[VEC_Z] = p.z >= sphere.position.z
		&& p.z <= (sphere.position.z + sphere.radius);
/*	if (v[0] && v[1] && v[2])
		printf("Point (%4.2f, %4.2f, %4.2f) "
			   "inside sphere (%4.2f, %4.2f, %4.2f):%4.2f.\n"
			   "\t(%s, %s, %s)\n",
			   p.x, p.y, p.z,
			   sphere.position.x, sphere.position.y, sphere.position.z,
			   sphere.radius,
			   v[VEC_X] ? "true" : "false",
			   v[VEC_Y] ? "true" : "false",
			   v[VEC_Z] ? "true" : "false");*/
	return (v[VEC_X] && v[VEC_Y] && v[VEC_Z]);
}

int					collision_test_point(t_vec3 p1, t_vec3 p2, t_real radius)
{
	t_sphere		s;

	s.position = p2;
	s.radius = radius;
	return (collision_test_sphere(p1, s));
}
