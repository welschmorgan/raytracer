/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:16:12 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:04:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_color					color_create(t_real r, t_real g, t_real b, t_real a)
{
	t_color				c;

	c.r = ft_clamp(r, 0.0f, 1.0f);
	c.g = ft_clamp(g, 0.0f, 1.0f);
	c.b = ft_clamp(b, 0.0f, 1.0f);
	c.a = ft_clamp(a, 0.0f, 1.0f);
	return (c);
}
