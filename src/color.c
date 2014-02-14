/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 17:46:59 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 17:47:11 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color					color_rgba(t_uchar r, t_uchar g, t_uchar b, t_uchar a)
{
	t_color				ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	ret.a = a;
	return (ret);
}

int						color_hex(t_color col)
{
	int					ret;

	ret = (col.a << 24) & 0xff;
	ret |= (col.a << 16) & 0xff;
	ret |= (col.a << 8) & 0xff;
	ret |= col.b & 0xff;
	return (ret);
}

t_color					color_ray(t_ray_result *ray)
{
	if (ray && ray->hit)
		return (color_rgba(255, 255, 0, 0));
	return (color_rgba(255, 0, 0, 0));
}
