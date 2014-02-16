/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:18:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 14:37:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDERER_H
# define RENDERER_H

# include <libmath_vec3.h>
# include <libmath_vec2.h>
# include "material.h"

struct					s_engine;

/*
** Renderer structure
**  all the variables needed to render the raytraced
**  objects on screen.
*/
typedef struct			s_renderer
{
	t_vec2				pixel;
	t_ray_result		result;
	struct s_engine		*engine;
}						t_renderer;

t_ray_result			renderer_shoot_planes(t_renderer *r, t_ray *ray);
t_ray_result			renderer_shoot_spheres(t_renderer *r, t_ray *ray);
t_ray_result			renderer_shoot(t_renderer *r, t_ray ray);

int						render_image(struct s_engine *e);
t_renderer				*renderer_init(t_renderer *r, struct s_engine *e);
t_color					renderer_pass_ambient(t_renderer *r);
t_color					renderer_pass_diffuse(t_renderer *r);
t_renderer				*renderer_update(t_renderer *r);

#endif /* !RENDERER_H */
