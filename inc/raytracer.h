/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 05:43:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:20:11 by mwelsch          ###   ########.fr       */
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

typedef struct			s_color
{
	t_uchar				a;
	t_uchar				r;
	t_uchar				g;
	t_uchar				b;
}						t_color;

/*
** Camera structure:
**	a point of view of the scene
*/
typedef struct			s_camera
{
	t_vec3				position;
	t_vec3				direction;
	t_real				fovx;
	t_real				fovy;
	t_real				ncPlane;
	t_real				fcPlane;
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

typedef struct			s_sphere
{
	t_real				radius;
	t_vec3				position;
}						t_sphere;


# ifndef PI
#  define PI 3.141592
# endif


t_color					color_rgba(t_uchar r, t_uchar g, t_uchar b, t_uchar a);
int						color_hex(t_color col);
t_color					color_ray(t_ray_result *ray);

t_vec3					viewplane_point(t_vec2 uv, t_engine *e);
t_camera				*camera_init(t_engine *e, t_vec3 pos, t_vec3 lookat);
void					camera_lookat(t_engine *e, t_vec3 lookat);

char					*image_get_pixel(t_image *img, int x, int y);
void					image_set_pixel(t_engine *e, int x, int y, int color);

int						render_image(t_engine *e);

int						engine_init(t_engine *e,
									unsigned int width,
									unsigned int height,
									char *title);
int						collision_test_point(t_vec3 p1, t_vec3 p2,
											 t_real radius);
int						collision_test_sphere(t_vec3 point,
											  t_sphere sphere);


#endif /* !RAYTRACER_H */
