/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:38:59 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 22:08:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "mlx_env.h"

void	draw_square(struct s_mlx_env *env,
					t_line def)
{
	int		cy;
	t_line	l;

	cy = def.start.y;
	while (cy < def.end.y)
	{
		vec2_set(&l.start, def.start.x, cy);
		vec2_set(&l.end, def.end.x, cy);
		draw_line(env, l);
		cy++;
	}
}
