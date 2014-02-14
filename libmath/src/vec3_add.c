/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 07:17:18 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/13 07:22:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libmath.h"
#include <math.h>

t_vec3					vec3_add(t_vec3 a, t_vec3 b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	return (a);
}
