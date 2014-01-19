/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 22:01:04 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:35:07 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx_env.h"
#include "mlx_buffer.h"
#include "ray_result.h"
#include "draw.h"
#include "map.h"

void	draw_solid_slice(struct s_mlx_env *env, int column, int colour)
{
	t_line	l;

	if (env)
	{
		vec2_set(&l.start, column, 0.0f);
		vec2_set(&l.end, column, env->height);
		l.color = colour;
		draw_line(env, l);
	}
}

void	draw_slice_part(struct s_mlx_env *env,
						int column,
						t_vec2 part,
						int color)
{
	t_line	line;

	line.start.x = column;
	line.end.x = column;
	line.start.y = part.x;
	line.end.y = part.y;
	line.color = color;
	draw_line(env, l);
}

void	draw_slice(struct s_mlx_env *env,
				   struct s_ray_result *res,
				   int column)
{
	t_real			proj_plane_dist;
	t_real			final;
	t_line			l;

	if (!env || !res)
		return ;
	proj_plane_dist = (env->width / 2) / tan(RADIANS(30.0f));
	if (proj_plane_dist && res->distance)
	{
		final = env->map->scale / res->distance * proj_plane_dist;
		vec2_set(&l.start, 0, env->height / 2 - (final ? final / 2 : 0.0f));
		draw_slice_part(env, l.start, 0x0000ff00);
		vec2_set(&l.start,
				 env->height / 2 - (final ? final / 2 : 0.0f),
				 env->height / 2 + (final ? final / 2 : 0.0f));
		draw_slice_part(env, l.start, 0x00ff0000);
		vec2_set(&l.start, env->height / 2 + (final ? final / 2 : 0.0f), 0);
		draw_slice_part(env, l.start, 0x00ffff00);
	}
	else
		draw_solid_slice(env, column, 0x00000000);
}
