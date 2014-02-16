/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:18:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 11:06:20 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RENDERER_H
# define RENDERER_H

# include <libmath_vec3.h>
# include <libmath_vec2.h>
# include "material.h"

/*
** Sphere structure:
**  represents a sphere, with a position, a radius,
**  and a material
*/
typedef struct			s_sphere
{
	t_real				radius;
	t_vec3				position;
	t_material			*material;
}						t_sphere;

/*
** Light type enum:
**  not supported yet
*/
typedef enum			e_ltype
{
	LT_POINT,
	LT_SPOT,
	LT_DIR
}						t_ltype;

/*
** Light structure:
**  holds infos about a source of light
*/
typedef struct			s_light
{
	t_vec3				position;
	t_vec3				direction;
	t_ltype				type;
	t_material			*material;
}						t_light;

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
	t_sphere			*objects;
	t_light				*lights;
	unsigned char		nlights;
	unsigned char		nobjects;
}						t_renderer;

int						render_image(struct s_engine *e);
t_renderer				*renderer_init(t_renderer *r, struct s_engine *e);
t_color					renderer_pass_ambient(t_renderer *r);
t_color					renderer_pass_diffuse(t_renderer *r);
t_renderer				*renderer_update(t_renderer *r);
t_ray_result			renderer_shoot(t_renderer *r, t_ray ray);

#endif /* !RENDERER_H */
