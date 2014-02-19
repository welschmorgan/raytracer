/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_shoot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 21:35:47 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:03:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"


#include <libft_printf.h>
t_ray_result			renderer_shoot(t_renderer *r, t_ray ray)
{
	t_ray_result		res;
	t_dnode				*cur;

	res = ray_result_create(0, ray, 0.0, NULL);
	if (!r)
		return (res);
	r->result.ray = ray;
	vec3_norm(&r->result.ray.direction);
	cur = r->engine->scene->objects->tail;
	while (cur)
	{
		if (collision_test_object(r, &res, ((t_object*)cur->data)))
			break ;
		cur = cur->next;
	}
	r->result = res;
	return (res);
}
