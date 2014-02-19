/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 10:14:42 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/18 01:55:18 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIAL_H
# define MATERIAL_H

# include <libft_types.h>
# include <libmath_ray.h>
# define MATERIAL_NAME_LENGTH 84

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

typedef struct			s_material
{
	char				name[MATERIAL_NAME_LENGTH];
	t_color				specular;
	t_color				diffuse;
	t_color				ambient;
	t_real				shininess;
}						t_material;

t_color					color_div(t_color a, t_color b);
t_color					color_scale(t_color a, t_real scalar);
t_color					color_mul(t_color a, t_color b);
t_color					color_add(t_color a, t_color b);
t_color					color_sub(t_color a, t_color b);
t_color					color_uchar(t_uchar r, t_uchar g, t_uchar b, t_uchar a);
t_color					color_create(t_real r, t_real g, t_real b, t_real a);
int						color_hex(t_color col);
int						color_ray(t_ray_result *ray);

t_material				*material_new(char *name);
t_material				*material_init(t_material *m, char *name);
void					material_destroy(t_material **mat);
#endif /* !MATERIAL_H */
