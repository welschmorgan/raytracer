/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 23:22:15 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:22:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec2.h"
#include "camera.h"

int						camera_rotate(t_camera *cam,
									  t_real angle)
{
	float	s;
	float	c;
	t_vec2	p;
	t_vec2	new;

	s = sin(RADIANS(angle));
	c = cos(RADIANS(angle));
	p = cam->direction;
	new.x = p.x * c - p.y * s;
	new.y = p.x * s + p.y * c;
	vec2_set(&cam->direction, new.x, new.y);
	vec2_normalise(&cam->direction);
	return (1);
}
