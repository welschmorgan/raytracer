/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 08:10:29 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 08:12:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_vec3				sphere_normal(t_sphere *s,
								  t_vec3 p)
{
	t_vec3			dir;

	dir = vec3_sub(p, s->position);
	return (*vec3_norm(&dir));
}
