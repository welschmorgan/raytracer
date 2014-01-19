/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 06:24:30 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 06:29:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_env.h"
#include <stdlib.h>

int				mlx_handler_key(int keycode, t_mlx_env *env)
{
	(void)keycode;
	env->last_event = ME_KEY;
	if (env)
		return (env->events[ME_KEY](env, keycode));
	return (EXIT_SUCCESS);
}

int				mlx_handler_mouse(int button, int x, int y, t_mlx_env *env)
{
	env->last_event = ME_MOUSE;
	(void)button;
	(void)x;
	(void)y;
	if (env)
		return (env->events[ME_MOUSE](env, button, x, y));
	return (EXIT_SUCCESS);
}

int				mlx_handler_expose(t_mlx_env *env)
{
	env->last_event = ME_EXPOSE;
	if (env)
		return (env->events[ME_EXPOSE](env));
	return (EXIT_SUCCESS);
}

int				mlx_handler_loop(t_mlx_env *env)
{
	env->last_event = ME_FRAME;
	if (env)
		return (env->events[ME_FRAME](env));
	return (EXIT_SUCCESS);
}
