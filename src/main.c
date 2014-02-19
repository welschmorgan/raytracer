/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 05:32:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 02:44:53 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <libft_converters.h>
#include <libft_string.h>
#include <libft_printf.h>
#include "raytracer.h"

int						create_scene(t_scene *scn)
{
	t_material			*light_mat;
	t_material			*obj_mat;
	t_light				*light;
	t_sphere			*sphere;

	if (!scn)
		return (0);
	light_mat = scene_create_material(scn, "light_material");
	light_mat->specular = color_create(1.0, 1.0, 1.0, 1.0);
	light_mat->diffuse = color_create(1.0, 1.0, 1.0, 1.0);
	light_mat->ambient = color_create(0.0, 0.0, 0.0, 1.0);
	light_mat->shininess = 60.0;
	obj_mat = scene_create_material(scn, "obj_material");
	obj_mat->specular = color_create(1.0, 1.0, 1.0, 1.0);
	obj_mat->diffuse = color_create(1.0, 0.0, 0.0, 1.0);
	obj_mat->ambient = color_create(0.0, 0.0, 0.0, 1.0);
	obj_mat->shininess = 60.0;
	light = scene_create_light(scn,
							   LT_POINT,
							   vec3_create(10.0, 10.0, 10.0),
							   light_mat);
	sphere = scene_create_sphere(scn, "sphere001", obj_mat);
	return (1);
}

int						main(int ac, char **av)
{
	t_engine			*engine;
	static t_uint		width = 640;
	static t_uint		height = 480;
	static char			title[80] = {"RTV1"};
	t_parser_status		status;

	if (ac > 3)
		ft_strncpy(title, av[3], 80);
	if (ac > 2)
		height = ft_atoi(av[2]);
	if (ac > 1)
		width = ft_atoi(av[1]);
	engine = engine_create(width, height, title);
	if (engine)
	{
		if (scene_load("test.scene", &status))
		{
			ft_error("%s: %s: %s\n",
					 av[0], scene_parser_error(status.code),
					 status.message);
			return (status.code);
		}
		create_scene(engine->scene);
		mlx_loop(engine->core);
		engine_destroy(&engine);
	}
	return (RTE_SUCCESS);
}
