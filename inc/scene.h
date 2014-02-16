/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:30:21 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 14:34:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCENE_H
# define SCENE_H

# include <libmath_vec3.h>
# include "material.h"

struct					s_renderer;
/*
** Plane structure:
**  represents a 3d plane
*/
typedef struct			s_plane
{
	t_normal			normal;
	t_vec3				point;
	t_material			*material;
}						t_plane;

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
**  holds infos about a source of light.
*/
typedef struct			s_light
{
	t_vec3				position;
	t_vec3				direction;
	t_ltype				type;
	t_material			*material;
}						t_light;

/*
** Scene structure:
**  represents the world to be rendered.
*/
typedef struct			s_scene
{
	t_sphere			*spheres;
	t_light				*lights;
	t_plane				*planes;
	unsigned char		nplanes;
	unsigned char		nlights;
	unsigned char		nspheres;
	struct s_renderer	*renderer;
}						t_scene;

t_scene					*scene_init(t_scene *scn, struct s_renderer *r);

#endif /* !SCENE_H */
