/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:16:27 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 00:16:00 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CAMERA_H
# define CAMERA_H

# include <libft_types.h>
# include <libmath_vec3.h>
# include <libmath_vec2.h>

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
	struct s_camera		*camera;
}						t_viewplane;


/*
** Camera structure:
**  a point of view of the scene
*/
struct					s_engine;
typedef struct			s_camera
{
	t_vec3				position;
	t_vec3				direction;
	struct s_engine		*engine;
	t_real				fovx;
	t_real				fovy;
	t_vec3				up;
	t_vec3				right;
	t_viewplane			viewplane;
}						t_camera;

void					camera_destroy(t_camera **e);
t_camera				*camera_init(t_camera *cam, struct s_engine *e,
									 t_vec3 pos, t_vec3 lookat);
t_camera				*camera_new(struct s_engine *e,
									t_vec3 pos,
									t_vec3 lookat);
t_vec3					camera_viewplane_point(struct s_engine *e,
											   t_vec2 pixel);
t_camera				*camera_update_viewplane(t_camera *e);
void					camera_lookat(t_camera *e,
									  t_vec3 lookat);

#endif /* !CAMERA_H */
