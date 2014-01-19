/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:55:07 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 21:56:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "line.h"

t_line			*line_init(t_line *l)
{
	if (l)
	{
		vec2_set(&l->start, 0.0f, 0.0f);
		vec2_set(&l->end, 0.0f, 0.0f);
		l->color = 0x00000000;
	}
	return (l);
}

t_line			*line_set(t_line *l, t_vec2 *start, t_vec2 *end, int col)
{
	if (l)
	{
		l->start = *start;
		l->end = *end;
		l->color = col;
	}
	return (l);
}
