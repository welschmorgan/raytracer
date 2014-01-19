/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 00:30:52 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 21:18:37 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_memory.h>
#include <mlx.h>
#include <math.h>
#include "mlx_env.h"
#include "mlx_buffer.h"
#include "main.h"
#include "vec2.h"
#include "map.h"
#include "camera.h"
#include "ray_result.h"
#include "draw.h"

int		usage(const char *app_name)
{
	ft_printf("usage: %s map_name\n", app_name);
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	t_mlx_env	env;

	set_app_name(av[0]);
	ft_printf("%s\n", get_app_title());
	if (ac != 2)
		return (usage(av[0]));
	if (!mlx_env_init(&env, 640, 480, get_app_title()))
		return (EXIT_FAILURE);
	if (!map_load(av[1], env.map))
		return (EXIT_FAILURE);
	vec2_set(&env.camera->direction, 0.0f, 1.0f);
	vec2_set(&env.camera->position,
			 5.0f,
			 5.0f);
	mlx_event(&env, ME_KEY, event_handler);
	mlx_event(&env, ME_MOUSE, event_handler);
	mlx_event(&env, ME_EXPOSE, event_handler);
	mlx_event(&env, ME_FRAME, event_handler);
	mlx_loop(env.mlx);
	mlx_env_destroy(&env);
	return (EXIT_SUCCESS);
}
