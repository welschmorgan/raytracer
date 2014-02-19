/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 23:37:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/17 23:38:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_real			collision_test_sphere_a(t_vec3 *r_dir)
{
	return (ft_pow(r_dir->x, 2) + ft_pow(r_dir->y, 2) + ft_pow(r_dir->z, 2));
}

t_real			collision_test_sphere_b(t_ray *ray, t_vec3 *sphere_pos)
{
	t_vec3				osp;
	t_vec3				dosp;

	osp = vec3_sub(ray->origin, *sphere_pos);
	dosp = vec3_mul(ray->direction, osp);
	return (2.0 * (dosp.x + dosp.y + dosp.z));
}

t_real			collision_test_sphere_c(t_ray *ray, t_sphere *sphere)
{
	return (ft_pow(ray->origin.x - sphere->position.x, 2)
			+ ft_pow(ray->origin.y - sphere->position.y, 2)
			+ ft_pow(ray->origin.z - sphere->position.z, 2)
			- ft_pow(sphere->radius, 2));
}
