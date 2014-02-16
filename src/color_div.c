/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:15:31 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 10:04:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_color					color_div(t_color a, t_color b)
{
	t_color				c;

	c.r = ft_clamp(a.r / b.r, 0.0f, 1.0f);
	c.g = ft_clamp(a.g / b.g, 0.0f, 1.0f);
	c.b = ft_clamp(a.b / b.b, 0.0f, 1.0f);
	c.a = ft_clamp(a.a / a.a, 0.0f, 1.0f);
	return (c);
}
