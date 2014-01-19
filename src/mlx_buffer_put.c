/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:07:57 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 16:58:58 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <mlx.h>
#include <libft_printf.h>
#include "mlx_buffer.h"
#include "mlx_env.h"

int		mlx_buffer_put(t_mlx_buffer *buf, int x, int y, int col)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*ptr;
	char	*color;
	int		color_bytes;

	if (!buf)
		return (EXIT_FAILURE);
	if (x >= buf->env->width || x < 0)
		return (EXIT_FAILURE);
	if (y >= buf->env->height || y < 0)
		return (EXIT_FAILURE);
	data = mlx_get_data_addr(buf->env->buffer->data, &bpp, &sizeline, &endian);
	if (!data)
		return (EXIT_FAILURE);
	ptr = data + (x * (bpp / 8) + y * sizeline);
	if (!ptr)
		return (EXIT_FAILURE);
#ifdef _DEBUG
	ft_printf("Image data[%i, %i]: "
			  "(bpp:%i, sizeline:%i, endian:%i, color:0x%x)\n",
			  x, y, bpp, sizeline, endian, col);
#endif
	color_bytes = mlx_get_color_value(buf->env->mlx, col);
	color = (char*)&color_bytes;
	if (!endian)
	{
		ptr[0] = color[0];
		ptr[1] = color[1];
		ptr[2] = color[2];
		ptr[3] = color[3];
	}
	else
	{
		ptr[0] = color[3];
		ptr[1] = color[2];
		ptr[2] = color[1];
		ptr[3] = color[0];
	}
	buf->dirty = TRUE;
	return (EXIT_SUCCESS);
}
