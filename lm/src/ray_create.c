/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:04:02 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 16:52:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libmath.h"

t_ray					ray_create(t_vec3 origin, t_vec3 end)
{
	t_ray				r;

	r.origin = origin;
	r.direction = vec3_sub(end, origin);
	return (r);
}
