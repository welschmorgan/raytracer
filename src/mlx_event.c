/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 06:25:47 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 06:30:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_env.h"
#include <libft_string.h>
#include <libft_printf.h>
#include <stdlib.h>

void			mlx_event(t_mlx_env *env,
						  t_mlx_event type,
						  t_event_handler hdlr)
{
	if (!env)
		return ;
	env->events[type] = hdlr;
}

const char		*mlx_event_name(t_mlx_event evt)
{
	static char		ret[10] = {0};

	if (evt == ME_EXPOSE)
		ft_strncpy(ret, "expose", 10);
	else if (evt == ME_KEY)
		ft_strncpy(ret, "key_press", 10);
	else if (evt == ME_MOUSE)
		ft_strncpy(ret, "mouse", 10);
	else if (evt == ME_FRAME)
		ft_strncpy(ret, "frame", 10);
	else
		ft_strncpy(ret, "unknown", 10);
	return (ret);
}

int				mlx_event_handler(t_mlx_env *env,
								  int xtra,
								  int xtra2,
								  int xtra3)
{
	(void)xtra, (void)xtra2, (void)xtra3;
	(void)env;
#ifdef _DEBUG
	ft_printf("Uncatched event: %s(0x%x)\n",
			  mlx_event_name(env->last_event),
			  env->last_event);
#endif
	return (EXIT_SUCCESS);
}
