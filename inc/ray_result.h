/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_result.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 00:01:51 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 18:43:25 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RAY_RESULT_H
# define RAY_RESULT_H

# include "vec2.h"

typedef struct	s_ray_result
{
	t_vec2		position;
	int			hit;
	t_real		distance;
}				t_ray_result;

t_ray_result	*ray_result_init(t_ray_result *res);
t_vec2			ray_get_point(t_vec2 start,
							  t_vec2 end,
							  t_real distance);

#endif /* !RAY_RESULT_H */
