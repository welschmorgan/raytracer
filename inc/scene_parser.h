/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 21:21:12 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 01:43:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "object.h"
# include <libft_config.h>

# define OBJECT_TYPE_LENGTH 21
# define PARSER_FLOAT_LENGTH 32
# define PARSER_INT_LENGTH 32

typedef struct			s_sphere_decl
{
	char				radius[PARSER_FLOAT_LENGTH];
	char				position[3][PARSER_FLOAT_LENGTH];
}						t_sphere_decl;

typedef struct			s_light_decl
{
	char				position[3][PARSER_FLOAT_LENGTH];
	char				direction[3][PARSER_FLOAT_LENGTH];
	char				type[PARSER_INT_LENGTH];
}						t_light_decl;

typedef struct			s_plane_decl
{
	char				normal[3][PARSER_FLOAT_LENGTH];
	char				point[3][PARSER_FLOAT_LENGTH];
}						t_plane_decl;

typedef union			u_objdata_decl
{
	t_sphere_decl		sphere;
	t_plane_decl		plane;
	t_light_decl		light;
}						t_objdata_decl;

typedef struct			s_objdecl
{
	char				name[OBJECT_NAME_LENGTH];
	char				type[OBJECT_TYPE_LENGTH];
	t_objdata_decl		data;
	char				material[MATERIAL_NAME_LENGTH];
}						t_objdecl;

typedef enum			e_parser_error
{
	SPE_NONE,
	SPE_INVALID_STREAM,
	SPE_INTERNAL,
	SPE_COUNT,
	SPE_SUCCESS = SPE_NONE
}						t_parser_error;

typedef struct			s_parser_status
{
	t_parser_error		code;
	char				message[1024];
}						t_parser_status;

typedef  struct			s_parser_env
{
	t_uint				line_id;
	char				**line_toks;
	char				*line;
	t_parser_status		*status;
	int					descriptor;
	char				filename[FT_PATH_MAX];
}						t_parser_env;

t_parser_env			*scene_parser_init(t_parser_env *e,
										   t_parser_status *status,
										   const char *filename);
int						scene_parser_step(t_parser_env *e);
void					scene_parser_close(t_parser_env *e);
char					*scene_parser_error(t_parser_error code);
int						scene_parser_status(t_parser_status *s,
											t_parser_error code,
											const char * msg);
int						scene_load(const char *filename,
								   t_parser_status *status);
int						scene_save(const char *filename,
								   t_parser_status *status);

#endif /* !SCENE_PARSER_H */
