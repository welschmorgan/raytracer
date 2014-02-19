/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:18:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:52:39 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDERER_H
# define RENDERER_H

# include <libmath_vec3.h>
# include <libmath_vec2.h>
# include "material.h"
# include "scene.h"

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

int						renderer_test_collisions(t_renderer *r,
												 t_ray_result *res,
												 t_object *obj);
t_color					renderer_light_compute(t_renderer *r, t_light *l);
t_color					renderer_light_compute_list(t_renderer *r,
													t_dlist *lst);
t_real					renderer_light_compute_angle(t_normal surf_normal,
													 t_vec3 contact_pt,
													 t_light *l);
t_ray_result			renderer_shoot(t_renderer *r, t_ray ray);

int						render_image(struct s_engine *e);
t_renderer				*renderer_new(struct s_engine *e);
t_renderer				*renderer_init(t_renderer *r, struct s_engine *e);
t_renderer				*renderer_update(t_renderer *r);

#endif /* !RENDERER_H */
