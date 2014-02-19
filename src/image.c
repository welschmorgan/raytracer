/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:43:13 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 02:40:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <libft_memory.h>

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

	pos = (x * (e->img->bpp / 8)) + (y * e->img->size_line);
	color = mlx_get_color_value(e->core, color);
	col = (char*)&color;
	e->img->data[pos + 0] = col[0];
	e->img->data[pos + 1] = col[1];
	e->img->data[pos + 2] = col[2];
	e->img->data[pos + 3] = col[3];
}

t_image					*image_init(t_image *i,
									struct s_engine *e,
									t_uint width,
									t_uint height)
{
	if (i)
	{
		i->engine = e;
		i->data = NULL;
		i->ptr = NULL;
		i->width = width;
		i->height = height;
		i->bpp = 0;
		i->size_line = 0;
		i->endian = 0;
		if ((i->ptr = mlx_new_image(e->core, width, height)) == NULL)
			ft_memdel((void**)&i);
	}
	return (i);
}

void					image_destroy(t_image **e)
{
	if (e)
	{
		if (*e && (*e)->engine->core)
			mlx_destroy_image((*e)->engine->core, (*e)->ptr);
		ft_memdel((void**)e);
	}
}

t_image					*image_create(struct s_engine *e,
									  t_uint width,
									  t_uint height)
{
	t_image				*i;

	i = (t_image*)ft_memalloc(sizeof(t_image));
	return (image_init(i, e, width, height));
}
