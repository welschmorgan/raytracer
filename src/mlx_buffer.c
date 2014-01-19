/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:17:04 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 16:39:45 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft_memory.h>
#include <libft_printf.h>
#include "mlx_env.h"
#include "mlx_buffer.h"

t_mlx_buffer	*mlx_buffer_new(struct s_mlx_env *env)
{
	t_mlx_buffer	*buffer;

	buffer = ft_memalloc(sizeof(t_mlx_buffer));
	if (buffer)
		mlx_buffer_init(buffer, env);
	return (buffer);
}

t_mlx_buffer	*mlx_buffer_init(t_mlx_buffer *buf, struct s_mlx_env *env)
{
	if (!buf)
		return (buf);
	buf->env = env;
	buf->dirty = TRUE;
	buf->data = mlx_new_image(env->mlx, env->width, env->height);
	return (buf);
}

int		mlx_buffer_clear(t_mlx_buffer *buf, int col)
{
	int		x;
	int		y;

	y = 0;
	while (y < buf->env->height)
	{
		x = 0;
		while (x < buf->env->width)
		{
			mlx_buffer_put(buf, x, y, col);
			x ++;
		}
		y ++;
	}
	buf->dirty = FALSE;
	return (EXIT_SUCCESS);
}

int				mlx_buffer_upload(t_mlx_buffer *buf)
{
	if (buf && buf->dirty)
	{
		mlx_put_image_to_window(buf->env->mlx, buf->env->win, buf->data, 0, 0);
/*		mlx_buffer_clear(buf, 0);*/
		buf->dirty = FALSE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
