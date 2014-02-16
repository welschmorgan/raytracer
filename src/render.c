/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:56:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 09:44:01 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>
#include <time.h>
#include <math.h>

static clock_t tbegin;

void					progress_status(t_engine *e,
										float progress,
										float telapsed)
{
	ft_printf("\r[render:%ix%i]\t%i %% - %i seconds.",
			  e->img.width, e->img.height,
			  (int)progress,
			  (int)telapsed);
}

int						render_image(t_engine *e)
{
	t_renderer			renderer;

	renderer_init(&renderer, e);
	progress_status(e, 0.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	tbegin = clock();
	while (renderer.pixel.y < (t_real)e->img.height)
	{
		renderer.pixel.x = 0.0f;
		progress_status(e, ((float)renderer.pixel.y
							/ (float)e->img.height) * 100.0f,
						(clock() - tbegin) / CLOCKS_PER_SEC);
		while (renderer.pixel.x < (t_real)e->img.width)
		{
			renderer_update(&renderer);
			renderer.pixel.x++;
		}
		renderer.pixel.y++;
	}
	progress_status(e, 100.0f, (clock() - tbegin) / CLOCKS_PER_SEC);
	ft_printf("\n[render:%ix%i]:\t%i %% - "
			  "uploading to video memory: ",
			  e->img.width, e->img.height);
	mlx_put_image_to_window(e->core, e->win, e->img.ptr, 0, 0);
	printf("done\n");
	return (1);
}
