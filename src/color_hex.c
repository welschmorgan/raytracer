/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 09:16:28 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 09:16:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"

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
