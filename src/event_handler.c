/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:01:59 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 20:42:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mlx_env.h"
#include "camera.h"
#include "ray_result.h"
#include "draw.h"
#include "map.h"
#include "mlx_buffer.h"
#include <stdlib.h>
#include <libft_printf.h>

int		event_handler(struct s_mlx_env *env, int a, int b, int c)
{
	(void)a;
	(void)b;
	(void)c;
	if (env->last_event == ME_KEY)
	{
		if (a == 65307)
		{
			printf("User requested shutdown.\n");
			exit(EXIT_SUCCESS);
		}
		else if (a == 0xff51)
		{
			printf("Key left\n");
			camera_rotate(env->camera, -5.0f);
		}
		else if (a == 0xff53)
		{
			printf("Key right\n");
			camera_rotate(env->camera, 5.0f);
		}
		else if (a == 0xff52 || a == 'w')
		{
			printf("Key up\n");
			camera_translate(env->camera, env->map,
							 env->camera->direction.x * env->map->scale,
							 env->camera->direction.y * env->map->scale);
		}
		else if (a == 'a')
		{
			camera_translate(env->camera, env->map, -env->map->scale * 2, 0.0f);
		}
		else if (a == 'd')
		{
			camera_translate(env->camera, env->map, env->map->scale * 2, 0.0f);
		}
		else if (a == 0xff54 || a == 's')
		{
			printf("Key down\n");
			camera_translate(env->camera, env->map,
							 -env->camera->direction.x * env->map->scale,
							 -env->camera->direction.y * env->map->scale);
		}
		else
			ft_printf("User pressed key '%c' (0x%x)\n", a, a);
	}
	else if (env->last_event == ME_FRAME)
	{
		draw_frame(env->buffer);
		mlx_buffer_upload(env->buffer);
	}
	else if (env->last_event == ME_EXPOSE)
	{
		draw_frame(env->buffer);
		mlx_buffer_upload(env->buffer);
	}
	return (EXIT_SUCCESS);
}
