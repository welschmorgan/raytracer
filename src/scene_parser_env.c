/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 06:10:25 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/19 02:15:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_parser.h"
#include <libft_string.h>
#include <libft_memory.h>
#include <unistd.h>
#include <fcntl.h>

t_parser_env			*scene_parser_init(t_parser_env *e,
										   t_parser_status *status,
										   const char *filename)
{
	if (e)
	{
		e->line_id = 0;
		e->line = NULL;
		e->status = status;
		e->line_toks = NULL;
		if (e->status)
		{
			e->status->code = SPE_NONE;
			ft_strncpy(e->status->message,
					   "",
					   1024);
			ft_strncpy(e->filename,
					   "",
					   FT_PATH_MAX);
			e->descriptor = open(filename, O_RDONLY);
		}
	}
	return (e);
}

char					**scene_parser_tokenise(char *str)
{
	char				**toks;

	ft_strtrim(str, FT_WHITESPACE_SEPS);
	toks = ft_strtok(str, FT_WHITESPACE_SEPS);
	if (!toks)
	{
		toks = ft_memalloc(sizeof(char*) * 2);
		toks[0] = ft_strdup(str);
		toks[1] = NULL;
	}
	return (toks);
}

int						scene_parser_step(t_parser_env *e)
{
	if (e)
	{
		if (e->line_toks)
			ft_tokdel(&e->line_toks);
		if (e->line)
			ft_strdel(&e->line);
		e->line_toks = NULL;
		e->line = NULL;
		e->line_id++;
		if (ft_getline(e->descriptor, &e->line) <= 0)
			return (0);
		if (e->line)
			e->line_toks = scene_parser_tokenise(e->line);
	}
	return (1);
}

void					scene_parser_close(t_parser_env *e)
{
	if (e)
	{
		close(e->descriptor);
		if (e->line)
			ft_strdel(&e->line);
		if (e->line_toks)
			ft_tokdel(&e->line_toks);
	}
}
