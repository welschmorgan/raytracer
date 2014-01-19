/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:59:00 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 18:54:09 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec2.h"

typedef struct	s_camera
{
	t_vec2		position;
	t_vec2		direction;
	t_real		fov;
	t_real		fovy;
}				t_camera;

struct			s_mlx_env;
struct			s_ray_result;
struct			s_map;
t_camera				*camera_set(t_camera *cam,
									t_vec2 position,
									t_vec2 direction);
t_camera				*camera_init(struct s_mlx_env *env,
									 t_camera *cam);
t_camera				*camera_new(struct s_mlx_env *env,
									t_vec2 position,
									t_vec2 look_at);
struct s_ray_result		camera_shoot_ray(struct s_mlx_env *env,
										 t_camera *cam,
										 t_real max_length,
										 t_real step);
t_vec2					camera_lookat(t_camera *cam,
									  t_vec2 point);
int						camera_rotate(t_camera *cam,
									  t_real degrees);
int						camera_translate(t_camera *cam,
										 struct s_map *map,
										 t_real delta_x,
										 t_real delta_y);

#endif /* !CAMERA_H */
