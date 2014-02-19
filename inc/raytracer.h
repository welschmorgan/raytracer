/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 05:43:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 03:59:46 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include <mlx.h>
# include <libmath.h>
# include "renderer.h"
# include "camera.h"
# include "scene.h"

# define VEC_X			0
# define VEC_Y			1
# define VEC_Z			2

struct					s_engine;
/*
** Image structure:
**	represents the video buffer for the screen
*/
typedef struct			s_image
{
	char				*data;
	void				*ptr;
	int					width;
	int					height;
	int					bpp;
	int					size_line;
	int					endian;
	struct s_engine		*engine;
}						t_image;


/*
** Engine structure:
**	all the variables needed in the app
*/
typedef struct			s_engine
{
	void				*core;
	void				*win;
	t_renderer			*renderer;
	t_image				*img;
	t_camera			*cam;
	t_scene				*scene;
}						t_engine;

typedef enum			e_rt_error
{
	RTE_NONE,
	RTE_INIT,
	RTE_WINDOW,
	RTE_IMAGE,
	RTE_INTERNAL,
	RTE_RENDERING,
	RTE_SUCCESS = RTE_NONE
}						t_rt_error;

# ifndef PI
#  define PI 3.141592
# endif

t_engine				*engine_reset(t_engine *e);
void					engine_destroy(t_engine **e);
t_engine				*engine_create();
int						engine_init(t_engine *e,
									unsigned int width,
									unsigned int height,
									char *title);

char					*image_get_pixel(t_image *img, int x, int y);
void					image_set_pixel(t_engine *e, int x, int y, int color);
void					image_destroy(t_image **e);
t_image					*image_create(struct s_engine *e,
									  t_uint width,
									  t_uint height);
t_image					*image_init(t_image *i,
									struct s_engine *e,
									t_uint width,
									t_uint height);

t_vec3					sphere_normal(t_sphere *sphere,
									  t_vec3 pt);

t_real					collision_test_sphere_a(t_vec3 *r_dir);
t_real					collision_test_sphere_b(t_ray *ray, t_vec3 *sphere_pos);
t_real					collision_test_sphere_c(t_ray *ray, t_sphere *sphere);

int						collision_test_sphere(t_ray_result *res,
											  t_sphere *sphere);
int						collision_test_plane(t_ray_result *result,
											 t_plane *plane);
int						collision_test_object(t_renderer *r,
											  t_ray_result *res,
											  t_object *obj);

#endif /* !RAYTRACER_H */
