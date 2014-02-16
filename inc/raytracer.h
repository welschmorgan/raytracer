/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 05:43:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/16 08:29:05 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H
# include <mlx.h>
# include <libmath.h>

# define VEC_X			0
# define VEC_Y			1
# define VEC_Z			2

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
}						t_image;

/*
** Viewplane structure:
**  holds viewplane infos
*/
typedef struct			s_viewplane
{
	t_vec3				position;
	t_real				distance;
	t_real				width;
	t_real				height;
}						t_viewplane;


/*
** Camera structure:
**  a point of view of the scene
*/
typedef struct			s_camera
{
	t_vec3				position;
	t_vec3				direction;
	t_real				fovx;
	t_real				fovy;
	t_vec3				up;
	t_vec3				right;
	t_viewplane			viewplane;
}						t_camera;

/*
** Engine structure:
**	all the variables needed in the app
*/
typedef struct			s_engine
{
	void				*core;
	void				*win;
	t_image				img;
	t_camera			cam;
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

typedef struct			s_material
{
	float				specular[4];
	float				diffuse[4];
	float				emissive[4];
	float				shininess;
}						t_material;

typedef struct			s_sphere
{
	t_real				radius;
	t_vec3				position;
	t_material			*material;
}						t_sphere;

/*
** Light type enum:
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

typedef enum			e_color_part
{
	ALPHA,
	RED,
	GREEN,
	BLUE
}						t_color_part;

typedef struct			s_color
{
	t_real				r;
	t_real				g;
	t_real				b;
	t_real				a;
}						t_color;

# ifndef PI
#  define PI 3.141592
# endif

t_color					color_uchar(t_uchar r, t_uchar g, t_uchar b, t_uchar a);
t_color					color_create(t_real r, t_real g, t_real b, t_real a);
int						color_hex(t_color col);
int						color_ray(t_ray_result *ray, t_material *material);

t_vec3					viewplane_point(t_vec2 uv, t_engine *e);
t_camera				*camera_update_viewplane(t_engine *e);
t_camera				*camera_init(t_engine *e, t_vec3 pos, t_vec3 lookat);
void					camera_lookat(t_engine *e, t_vec3 lookat);

char					*image_get_pixel(t_image *img, int x, int y);
void					image_set_pixel(t_engine *e, int x, int y, int color);

int						render_image(t_engine *e);

int						engine_init(t_engine *e,
									unsigned int width,
									unsigned int height,
									char *title);

t_vec3					sphere_normal(t_sphere *sphere,
									  t_vec3 pt);

int						collision_test_point(t_vec3 p1, t_vec3 p2,
											 t_real radius);
int						collision_test_sphere(t_ray_result *res,
											  t_sphere *sphere);


#endif /* !RAYTRACER_H */
