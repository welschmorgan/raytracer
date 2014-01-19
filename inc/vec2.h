/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:01:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:26:45 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef VEC2_H
# define VEC2_H
# include <libft_types.h>

typedef struct	s_vec2
{
	t_real		x;
	t_real		y;
}				t_vec2;

#define RADIANS(a) (a * 3.14f / 180.0f)

extern t_vec2	VEC2_NULL;
extern t_vec2	VEC2_UNIT_X;
extern t_vec2	VEC2_UNIT_Y;
extern t_vec2	VEC2_UNIT_SCALE;

void			vec2_rotate(t_vec2 *v,
							t_real angle);
t_vec2			vec2_sub(t_vec2 a, t_vec2 b);
t_vec2			vec2_add(t_vec2 a, t_vec2 b);
t_vec2			vec2_mul(t_vec2 a, t_vec2 b);
t_vec2			vec2_scale(t_vec2 a, t_real b);
t_vec2			vec2_div(t_vec2 a, t_vec2 b);
void			vec2_sub_op(t_vec2 *a, t_vec2 *b, t_vec2 *result);
void			vec2_add_op(t_vec2 *a, t_vec2 *b, t_vec2 *result);
void			vec2_mul_op(t_vec2 *a, t_vec2 *b, t_vec2 *result);
void			vec2_div_op(t_vec2 *a, t_vec2 *b, t_vec2 *result);
t_vec2			vec2_operation(t_vec2 *a, t_vec2 *b,
							   void(*t_vec_operator)(
								   t_vec2 *,
								   t_vec2 *,
								   t_vec2 *));
t_vec2			*vec2_set(t_vec2 *v, t_real x, t_real y);
t_vec2			*vec2_reset(t_vec2 *v);
t_real			vec2_normalise(t_vec2 *v);
t_vec2			*vec2_dup(const t_vec2 *source);
t_vec2			*vec2_normalised_copy(const t_vec2 *source,
									  t_real *source_length);
t_real			vec2_length(t_vec2 v);

#endif /* !VEC2_H */
