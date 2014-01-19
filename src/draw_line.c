/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:35:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 22:04:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_env.h"
#include "mlx_buffer.h"
#include "vec2.h"
#include "draw.h"

void	draw_line(struct s_mlx_env *env,
					t_line line)
{
	int		i;
	t_vec2	dir;
	t_real	length;
	double	addx;
	double	addy;

	vec2_set(&dir, line.end.x - line.start.x, line.end.y - line.start.y);
	length = vec2_length(dir);
	addx = dir.x / length;
	addy = dir.y / length;

	dir.x = line.start.x;
	dir.y = line.start.y;
	i = 0;
	while (i < length)
	{
		mlx_buffer_put(env->buffer, dir.x, dir.y, line.color);
		dir.x += addx;
		dir.y += addy;
		i ++;
	}
}
