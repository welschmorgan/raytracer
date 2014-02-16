/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:15:14 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:04:04 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_color					color_scale(t_color a, t_real scalar)
{
	t_color				c;

	c.r = ft_clamp(a.r * scalar, 0.0f, 1.0f);
	c.g = ft_clamp(a.g * scalar, 0.0f, 1.0f);
	c.b = ft_clamp(a.b * scalar, 0.0f, 1.0f);
	c.a = ft_clamp(a.a * scalar, 0.0f, 1.0f);
	return (c);
}
