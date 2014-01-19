/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:58:32 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 23:35:43 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DRAW_H
# define DRAW_H

# include "line.h"

struct	s_mlx_env;
struct	s_mlx_buffer;
struct	s_ray_result;

int		draw_frame(struct s_mlx_buffer *buf);
void	draw_map(struct s_mlx_env *env);
void	draw_square(struct s_mlx_env *env,
					t_line line);
void	draw_line(struct s_mlx_env *env,
				  t_line line);

void	draw_2d(struct s_mlx_env *env);
void	draw_solid_slice(struct s_mlx_env *env, int column, int colour);
void	draw_slice_part(struct s_mlx_env *env,
						int column,
						t_vec2 part,
						int color);
void	draw_slice(struct s_mlx_env *env, struct s_ray_result *res, int column);

#endif /* !DRAW_H */
