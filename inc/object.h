/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 04:13:49 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 01:41:08 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef OBJECT_H
# define OBJECT_H

# include "material.h"

# define OBJECT_NAME_LENGTH 50

struct					s_object;
/*
** Plane structure:
**  represents a 3d plane
*/
typedef struct			s_plane
{
	t_normal			normal;
	t_vec3				point;
	t_material			*material;
	struct s_object		*object;
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
	struct s_object		*object;
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

typedef enum			e_objtype
{
	OT_NONE,
	OT_SPHERE,
	OT_PLANE,
	OT_LIGHT,
	OT_COUNT
}						t_objtype;

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
	struct s_object		*object;
}						t_light;


typedef union			u_objdata
{
	t_sphere			*sphere;
	t_plane				*plane;
	t_light				*light;
}						t_objdata;

typedef struct			s_object
{
	char				name[OBJECT_NAME_LENGTH];
	t_objtype			type;
	t_objdata			*data;
	t_material			*material;
}						t_object;

#endif /* !OBJECT_H */
