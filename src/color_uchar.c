/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_uchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:15:59 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 09:16:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

t_color					color_uchar(t_uchar r, t_uchar g, t_uchar b, t_uchar a)
{
	return (color_create(((float)r) / 255.0,
						 ((float)g) / 255.0,
						 ((float)b) / 255.0,
						 ((float)a) / 255.0));
}
