/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_lookat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 23:24:51 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:27:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec2.h"

t_vec2			camera_lookat(t_camera *cam, t_vec2 point)
{
	if (!cam)
		return (VEC2_NULL);
	camera_set(cam, cam->position, vec2_sub(point, cam->position));
	return (cam->direction);
}
