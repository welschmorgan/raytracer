/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 00:39:21 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/18 04:23:17 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <libft_printf.h>
#include <libft_memory.h>
#include <libft_string.h>
#include "mlx_env.h"
#include "mlx_buffer.h"
#include "main.h"
#include "map.h"
#include "camera.h"

t_mlx_env		*mlx_env_init(t_mlx_env *env,
							  int width,
							  int height,
							  char *title)
{
	int					i;
	static t_vec2		pos = {0.0f, 0.0f};
	static t_vec2		la = {1.0f, 1.0f};

	if (!env)
		return (NULL);
	env->mlx = mlx_init();
	if (!env->mlx)
		die("couldn't initialise mlx");
	env->win = mlx_new_window(env->mlx, width, height, title);
	if (!env->win)
		die("couldn't create mlx window");
	env->width = width;
	env->height = height;
	env->camera = camera_new(env, pos, la);
	if (!env->camera)
		die("couldn't create camera");
	env->map = map_new(env);
	if (!env->camera)
		die("couldn't create map");
	ft_memset(env->events, 0, sizeof(mlx_event_table));
	env->buffer = mlx_buffer_new(env);
	if (!env->camera)
		die("couldn't create buffer");
	env->last_event = ME_NONE;
	i = 0;
	while (i < ME_COUNT)
	{
		env->events[i] = mlx_event_handler;
		i ++;
	}
	mlx_key_hook(env->win, mlx_handler_key, env);
	mlx_mouse_hook(env->win, mlx_handler_mouse, env);
	mlx_expose_hook(env->win, mlx_handler_expose, env);
	mlx_loop_hook(env->mlx, mlx_handler_loop, env);
	return (env);
}

t_mlx_env		*mlx_env_create(int width, int height, char *title)
{
	t_mlx_env	*ret;
	ret = (t_mlx_env*)malloc(sizeof(t_mlx_env));
	if (!ret)
		return (NULL);
	mlx_env_init(ret, width, height, title);
	return (ret);
}

void			mlx_env_destroy(t_mlx_env *env)
{
	if (env)
	{
		if (env->buffer)
		{
			mlx_destroy_image(env->mlx, env->buffer->data);
			ft_memdel((void**)&env->buffer);
		}
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		if (env->camera)
			ft_memdel((void**)env->camera);
		if (env->map)
			map_destroy(&env->map);
		ft_memdel((void**)&env);
	}
}
