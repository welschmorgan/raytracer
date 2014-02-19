/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:56:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:33:54 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

#include <time.h>
#include <math.h>

void					render_infos(t_engine *e)
{
	static char			buf[1024] = {0};

	ft_strcpy(buf, "Materials: ");
	ft_strcat(buf, ft_ntoa(e->scene->materials->size, 10));
	mlx_string_put(e->core, e->win, 5, 10, 0xffffff00, buf);
	ft_strcpy(buf, "Lights: ");
	ft_strcat(buf, ft_ntoa(e->scene->lights->size, 10));
	mlx_string_put(e->core, e->win, 5, 20, 0xffffff00, buf);
	ft_strcpy(buf, "Objects: ");
	ft_strcat(buf, ft_ntoa(e->scene->objects->size, 10));
	mlx_string_put(e->core, e->win, 5, 30, 0xffffff00, buf);
}

void					progress_status(t_engine *e,
										float progress,
										float telapsed)
{
	ft_printf("\r[render:%ix%i]\t%i %% - %i seconds.",
			  e->img->width, e->img->height,
			  (int)progress,
			  (int)telapsed);
}

int						render_image(t_engine *e)
{
	while (e->renderer->pixel.y < (t_real)e->img->height)
	{
		e->renderer->pixel.x = 0.0f;
		while (e->renderer->pixel.x < (t_real)e->img->width)
		{
			renderer_update(e->renderer);
			e->renderer->pixel.x++;
		}
		e->renderer->pixel.y++;
	}
	mlx_put_image_to_window(e->core, e->win, e->img->ptr, 0, 0);
	render_infos(e);
	return (1);
}
