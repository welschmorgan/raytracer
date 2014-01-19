/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:57:45 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 22:02:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_env.h"
#include "mlx_buffer.h"
#include "map.h"
#include "camera.h"
#include "ray_result.h"
#include <math.h>
#include <stdlib.h>
#include <libft_printf.h>
#include <stdio.h>

int		draw_perspective(struct s_mlx_env *env)
{
	int				col;
	t_real			step;
	t_vec2			start;
	t_ray_result	res;

	step = env->camera->fov / env->width;
	col = 0;
	start = env->camera->direction;
	vec2_rotate(&start, -env->camera->fov * 0.5f);
	while (col < env->width)
	{
		res = map_shoot_ray(env->map,
							env->camera->position,
							start,
							0.1f);
		draw_slice(env, &res, col);
		vec2_rotate(&start, step);
		col++;
	}
	return (1);
}

int		draw_frame(struct s_mlx_buffer *buf)
{
	draw_perspective(buf->env);
	return (EXIT_SUCCESS);
}
