/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_buffer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 15:19:00 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 16:44:30 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BUFFER_H
# define MLX_BUFFER_H
# include <libft_types.h>

struct						s_mlx_env;
typedef struct				s_mlx_buffer
{
	void					*data;
	t_bool					dirty;
	struct s_mlx_env		*env;
}							t_mlx_buffer;

t_mlx_buffer	*mlx_buffer_new(struct s_mlx_env *env);
t_mlx_buffer	*mlx_buffer_init(t_mlx_buffer *buf, struct s_mlx_env *env);
int				mlx_buffer_upload(t_mlx_buffer *buf);
int				mlx_buffer_clear(t_mlx_buffer *buf, int col);
int				mlx_buffer_put(t_mlx_buffer *buf, int x, int y, int col);

#endif /* !MLX_BUFFER_H */
