/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 00:39:08 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/18 04:22:22 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MLX_ENV_H
# define MLX_ENV_H

typedef enum				e_mlx_event
{
	ME_NONE,
	ME_EXPOSE,
	ME_KEY,
	ME_MOUSE,
	ME_FRAME,
	ME_COUNT
}							t_mlx_event;

# define COLOR_RED 0x00FF0000
# define COLOR_GREEN 0x0000FF00
# define COLOR_BLUE 0x000000FF
# define COLOR_BLACK 0x00000000
# define COLOR_YELLOW (COLOR_GREEN | COLOR_BLUE)
# define COLOR_PURPLE (COLOR_RED | COLOR_BLUE)

typedef int					(*t_event_handler)();
typedef t_event_handler		mlx_event_table[ME_COUNT];

struct						s_mlx_buffer;
typedef struct				s_mlx_env
{
	void					*mlx;
	void					*win;
	struct s_mlx_buffer		*buffer;
	struct s_camera			*camera;
	struct s_map			*map;
	int						width;
	int						height;
	mlx_event_table			events;
	t_mlx_event				last_event;
}							t_mlx_env;

const char					*mlx_event_name(t_mlx_event evt);
void						mlx_event(t_mlx_env *env,
									  t_mlx_event type,
									  t_event_handler hdlr);
t_mlx_env					*mlx_env_init(t_mlx_env *env,
										  int width, int height,
										  char *title);
void						mlx_env_destroy(t_mlx_env *env);
t_mlx_env					*mlx_env_create(int width, int height,
											char *title);

int				mlx_event_handler(t_mlx_env *env,
								  int xtra,
								  int xtra2,
								  int xtra3);
int				mlx_handler_key(int keycode, t_mlx_env *env);
int				mlx_handler_mouse(int button, int x, int y, t_mlx_env *env);
int				mlx_handler_expose(t_mlx_env *env);
int				mlx_handler_loop(t_mlx_env *env);

#endif /* !MLX_ENV_H */
