/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 21:20:51 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 01:43:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scene.h"
#include "scene_parser.h"
#include <libft_string.h>
#include <libft_printf.h>
#include <unistd.h>

static char				*g_scene_parser_errors[SPE_COUNT + 1] = {
	"success",
	"invalid stream",
	"internal"
	"unknown"
};

int						scene_parser_status(t_parser_status *s,
											t_parser_error code,
											const char * msg)
{
	if (s)
	{
		s->code = code;
		ft_strncpy(s->message, msg ? msg : (const char *)"", 1024);
	}
	return (code);
}

char					*scene_parser_error(t_parser_error code)
{
	if (code < SPE_COUNT)
		return (g_scene_parser_errors[code]);
	return (g_scene_parser_errors[SPE_COUNT]);
}

int						scene_parser_line(t_parser_env *e)
{

	if (!e)
		return (SPE_INTERNAL);
	if (!e->line || e->line[0] == '#')
		return (SPE_SUCCESS);
	return (scene_parser_status(e->status, SPE_SUCCESS, NULL));
}

int						scene_load(const char *filename,
								   t_parser_status *status)
{
	t_parser_env		env;

	scene_parser_init(&env, status, filename);
	if (env.descriptor == -1)
	{
		ft_printf("Waiting for scene description from standard input:\n");
		env.descriptor = STDIN_FILENO;
	}
	while (scene_parser_step(&env))
	{
		if (scene_parser_line(&env))
			return (env.status->code);
		ft_printf("Line(%u): %s\n", env.line_id, env.line);
	}
	scene_parser_close(&env);
	return (env.status->code);

}

int						scene_save(const char *filename,
								   t_parser_status *status)
{
	(void)filename;
	(void)status;
	return (0);
}
