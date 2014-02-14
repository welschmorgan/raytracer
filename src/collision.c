/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:14:01 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:40:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_string.h>
#include <libft_printf.h>

char				*vec3_tostring(t_vec3 v)
{
	static char		buf[128] = {0};

	ft_strclr(buf);
	ft_snprintf((char**)&buf, 128, "%i.%i,%i.%i,%i.%i",
				(int)v.x, (int)(1000.0f * (v.x / (t_real)(int)v.x)),
				(int)v.y, (int)(1000.0f * (v.x / (t_real)(int)v.x)),
				(int)v.z, (int)(1000.0f * (v.x / (t_real)(int)v.x)));
	return (buf);
}

int					sphere_tostring(t_sphere s)
{
	static char		buf[128] = {0};

	ft_strclr(buf);
	ft_snprintf((char**)&buf, 128, "position:%s, radius:%i.%i",
				vec3_tostring(v));
	return (buf);
}

int					collision_test_sphere(t_vec3 p, t_sphere sphere)
{
	int					v[3];

	v[VEC_X] = p.x >= sphere.position.x
		&& p.x <= (sphere.position.x + sphere.radius);
	v[VEC_Y] = p.x >= sphere.position.x
		&& p.x <= (sphere.position.x + sphere.radius);
	v[VEC_X] = p.z >= sphere.position.z
		&& p.z <= (sphere.position.z + sphere.radius);
	return (v[VEC_X] && v[VEC_Y] && v[VEC_Z]);
}

int					collision_test_point(t_vec3 p1, t_vec3 p2, t_real radius)
{
	t_sphere		s;

	s.position = p2;
	s.radius = radius;
	return (collision_test_sphere(p1, s));
}
