/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:45:10 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:06:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"
#include <libft_printf.h>

int						on_key_press(int key, t_engine *engine)
{
	(void)engine;
	ft_printf("Keypress: %i\n", key);
	if (key == 65307)
		exit(RTE_SUCCESS);
	return (1);
}

int						on_expose(t_engine *e)
{
	render_image(e);
	return (1);
}

int						engine_init(t_engine *e,
									unsigned int width,
									unsigned int height,
									char *title)
{
	if ((e->core = mlx_init()) == NULL)
		return (RTE_INIT);
	if ((e->win = mlx_new_window(e->core, width,
								 height, title)) == NULL)
		return (RTE_WINDOW);
	if ((e->img.ptr = mlx_new_image(e->core, width, height)) == NULL)
		return (RTE_IMAGE);
	e->img.width = width;
	e->img.height = height;
	camera_init(e,
				vec3_create(0.0f, 0.0f, 0.0f),
				vec3_create(0.0f, 0.0f, -100.0f));
	mlx_expose_hook(e->win, on_expose, e);
	mlx_key_hook(e->win, on_key_press, e);
	return (RTE_SUCCESS);
}

char					*image_get_pixel(t_image *img, int x, int y)
{
	if (!img || !img->data)
		return (NULL);
	return (img->data + (x * img->size_line + y));
}

void					image_set_pixel(t_engine *e, int x, int y, int color)
{
	char				*col;
	int					pos;

	pos = (x * (e->img.bpp / 8)) + (y * e->img.size_line);
	color = mlx_get_color_value(e->core, color);
	col = (char*)&color;
	e->img.data[pos + 0] = col[0];
	e->img.data[pos + 1] = col[1];
	e->img.data[pos + 2] = col[2];
	e->img.data[pos + 3] = col[3];
}
