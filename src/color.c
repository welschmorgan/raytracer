/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 17:46:59 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 09:00:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color					color_add(t_color a, t_color b)
{
	t_color				c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	c.a = a.a + a.a;
	return (c);
}

t_color					color_uchar(t_uchar r, t_uchar g, t_uchar b, t_uchar a)
{
	return (color_create(((float)r) / 255.0,
						 ((float)g) / 255.0,
						 ((float)b) / 255.0,
						 ((float)a) / 255.0));
}

t_color					color_create(t_real r, t_real g, t_real b, t_real a)
{
	t_color				c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

int						color_hex(t_color col)
{
	int					ret;

	ret = 0x000000;
	ret |= (unsigned char)(255.0f * col.a) << 24;
	ret |= (unsigned char)(255.0f * col.r) << 16;
	ret |= (unsigned char)(255.0f * col.g) << 8;
	ret |= (unsigned char)(255.0f * col.b);
	return (ret);
}

t_color					light_at(t_ray_result *res, t_light *l)
{
	t_vec3				lightv;
	t_vec3				contact;

	contact = vec3_add(res->ray.origin,
					   vec3_scale(res->ray.direction,
								  res->ray.distance));
	lightv = vec3_sub(contact, l->position);
}

int						color_ray(t_ray_result *ray)
{
	int					ret;
	t_sphere			*sphere;

	ret = 0xff000000;
	if (ray && ray->hit)
	{
		sphere = (t_sphere*)ray->data;
		if (mat)
		{
			ret |= (unsigned char)(255.0f
								   * sphere->material->emissive[RED]) << 16;
			ret |= (unsigned char)(255.0f
								   * sphere->material->emissive[GREEN]) << 8;
			ret |= (unsigned char)(255.0f
								   * sphere->material->emissive[BLUE]);
		}
		else
			ret = 0xffff0000;
	}
	return (ret);
}
