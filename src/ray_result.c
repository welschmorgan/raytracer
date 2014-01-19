/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 00:01:13 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 18:43:38 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_result.h"

t_ray_result	*ray_result_init(t_ray_result *res)
{
	vec2_set(&res->position, 0.0f, 0.0f);
	res->hit = 0;
	res->distance = 0.0f;
	return (res);
}

t_vec2			ray_get_point(t_vec2 start,
							  t_vec2 end,
							  t_real distance)
{
	t_vec2		ret;
	t_vec2		dir;

	dir = vec2_sub(end, start);
	vec2_normalise(&dir);
	ret = vec2_add(start, vec2_scale(dir, distance));
	return (ret);
}
