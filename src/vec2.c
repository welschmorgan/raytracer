/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:05:32 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:27:28 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include "vec2.h"
#include <libft_memory.h>

t_vec2			VEC2_NULL = {0.0f, 0.0f};
t_vec2			VEC2_UNIT_X = {1.0f, 0.0f};
t_vec2			VEC2_UNIT_Y = {0.0f, 1.0f};
t_vec2			VEC2_UNIT_SCALE = {1.0f, 1.0f};

void			vec2_rotate(t_vec2 *v,
							t_real angle)
{
	float	s;
	float	c;
	t_vec2	p;

	s = sin(RADIANS(angle));
	c = cos(RADIANS(angle));
	p.x = v->x * c - v->y * s;
	p.y = v->x * s + v->y * c;
	vec2_set(v, p.x, p.y);
	vec2_normalise(v);
}

void			vec2_sub_op(t_vec2 *a, t_vec2 *b, t_vec2 *result)
{
	if (!a || !b || !result)
		return ;
	vec2_set(result, a->x - b->x, a->y - b->y);
}

void			vec2_add_op(t_vec2 *a, t_vec2 *b, t_vec2 *result)
{
	if (!a || !b || !result)
		return ;
	vec2_set(result, a->x + b->x, a->y + b->y);
}

void			vec2_mul_op(t_vec2 *a, t_vec2 *b, t_vec2 *result)
{
	if (!a || !b || !result)
		return ;
	vec2_set(result, a->x * b->x, a->y * b->y);
}

void			vec2_div_op(t_vec2 *a, t_vec2 *b, t_vec2 *result)
{
	if (!a || !b || !result || !a->y || !b->y)
		return ;
	vec2_set(result, a->x / b->x, a->y / b->y);
}

t_vec2			vec2_operation(t_vec2 *a, t_vec2 *b,
							   void(*t_vec_operator)(t_vec2 *a,
													 t_vec2 *b,
													 t_vec2 *result))
{
	t_vec2		ret;

	t_vec_operator(a, b, &ret);
	return (ret);
}

t_vec2			vec2_sub(t_vec2 a, t_vec2 b)
{
	return (vec2_operation(&a, &b, vec2_sub_op));
}

t_vec2			vec2_add(t_vec2 a, t_vec2 b)
{
	return (vec2_operation(&a, &b, vec2_add_op));
}

t_vec2			vec2_mul(t_vec2 a, t_vec2 b)
{
	return (vec2_operation(&a, &b, vec2_mul_op));
}

t_vec2			vec2_scale(t_vec2 a, t_real b)
{
	static t_vec2		scalev;

	vec2_set(&scalev, b, b);
	return (vec2_operation(&a, &scalev, vec2_mul_op));
}

t_vec2			vec2_div(t_vec2 a, t_vec2 b)
{
	return (vec2_operation(&a, &b, vec2_div_op));
}

t_vec2			*vec2_set(t_vec2 *v, t_real x, t_real y)
{
	if (v)
	{
		v->x = x;
		v->y = y;
	}
	return (v);
}

t_vec2			*vec2_reset(t_vec2 *v)
{
	return (vec2_set(v, (t_real)0, (t_real)0));
}

t_real			vec2_normalise(t_vec2 *v)
{
	t_real		length;

	length = 0;
	if (v)
	{
		length = vec2_length(*v);
		if (!length)
			return (length);
		v->x /= length;
		v->y /= length;
	}
	return (length);
}

t_vec2			*vec2_dup(const t_vec2 *source)
{
	t_vec2		*ret;

	ret = ft_memalloc(sizeof(t_vec2));
	if (ret)
		ft_memcpy(ret, source, sizeof(t_vec2));
	return (ret);
}

t_vec2			*vec2_normalised_copy(const t_vec2 *v, t_real *v_length)
{
	t_vec2		*ret;

	if (!v || !v_length)
		return (NULL);
	ret = vec2_dup(v);
	if (!ret)
		return (NULL);
	*v_length = vec2_length(*ret);
	if (!*v_length)
		return (ret);
	ret->x /= *v_length;
	ret->y /= *v_length;
	return (ret);
}

t_real			vec2_length(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}
