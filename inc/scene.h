/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:30:21 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 15:44:56 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCENE_H
# define SCENE_H

# include <libmath_vec3.h>
# include <libft_dlist.h>
# include <scene_parser.h>
# include "material.h"

# define SCENE_NAME_LENGTH 50

typedef enum			e_color_id
{
	CLR_BLACK,
	CLR_WHITE,
	CLR_RED,
	CLR_GREEN,
	CLR_BLUE,
	CLR_MAGENTA,
	CLR_CYAN,
	CLR_YELLOW,
	CLR_COUNT
}						t_color_id;

typedef enum			e_material_id
{
	MTL_DEFAULT,
	MTL_FLOOR,
	MTL_SPHERES,
	MTL_LIGHT,
	MTL_COUNT
}						t_material_id;

extern const t_color	g_colors[CLR_COUNT];
extern const t_material	g_materials[MTL_COUNT];

struct					s_renderer;

/*
** Scene structure:
**  represents the world to be rendered.
*/
typedef struct			s_scene
{
	char				name[SCENE_NAME_LENGTH];
	t_dlist				*objects;
	t_dlist				*lights;
	t_dlist				*materials;
	struct s_renderer	*renderer;
	t_color				ambient;
}						t_scene;

char					*objtype_type2str(t_objtype t);
t_objtype				objtype_str2type(char * str);

void					objdata_destroy(t_objdata **data);
t_objdata				*objdata_create(struct s_object *object,
										t_objtype type);
t_objdata				*objdata_init(struct s_object *object,
									  t_objdata *data, t_objtype type);

t_object				*object_init(t_object *o,
									 const char *name,
									 t_objtype type,
									 t_material *mat);
t_object				*object_reset(t_object *o);
t_object				*object_create(const char *name,
									   t_objtype type,
									   t_material *mat);
void					object_destroy(t_object **obj);
t_normal				object_normal(t_object *o, t_vec3 contact);

t_scene					*scene_create(struct s_renderer *r,
									  char const *name);
t_scene					*scene_init(t_scene *scn, struct s_renderer *r,
									char const *name);
void					scene_material_destroy(t_dnode *n);
void					scene_light_destroy(t_dnode *n);
void					scene_object_destroy(t_dnode *obj);
t_object				*scene_object_get(t_scene *s, char *name);
void					scene_destroy(t_scene **scn);
void					scene_clear(t_scene *scn);
t_object				*scene_object_add(t_scene *scn, t_object *obj);
t_light					*scene_create_light(t_scene *scn,
											char *name,
											t_ltype type,
											t_material *mat);
t_material				*scene_create_material(t_scene *scn, char *name);
t_sphere				*scene_create_sphere(t_scene *scn, char *name,
											 t_material *mat);
t_plane					*scene_create_plane(t_scene *scn, char *name,
											t_material *mat);
t_object				*scene_create_object(t_scene *scn, char *name,
											 t_objtype type, t_material *mat);

#endif /* !SCENE_H */
