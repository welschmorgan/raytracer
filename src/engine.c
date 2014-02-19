/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 08:45:10 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 03:42:05 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"
#include <libft_printf.h>
#include <libft_memory.h>

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

t_engine				*engine_reset(t_engine *e)
{
	if (e)
	{
		if (e->scene)
			scene_clear(e->scene);
	}
	return (e);
}

void					engine_destroy(t_engine **e)
{
	if (e)
	{
		engine_reset(*e);
		ft_memdel((void**)&(*e)->img);
		ft_memdel((void**)&(*e)->cam);
		ft_memdel((void**)&(*e)->scene);
		ft_memdel((void**)e);
	}
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
	e->img = image_create(e, width, height);
	if (!e->img)
		return (RTE_IMAGE);
	e->cam = camera_new(e,
						vec3_create(0.0f, 0.0f, 10.0f),
						vec3_create(0.0f, 0.0f, 0.0f));
	e->scene = scene_create(e->renderer);
	mlx_expose_hook(e->win, on_expose, e);
	mlx_key_hook(e->win, on_key_press, e);
	return (RTE_SUCCESS);
}

t_engine				*engine_create(t_uint width, t_uint height, char *title)
{
	t_engine			*ret;

	ret = (t_engine*)ft_memalloc(sizeof(t_engine));
	if (engine_init(ret, width, height, title))
		engine_destroy(&ret);
	return (ret);
}
