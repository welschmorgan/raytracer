/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:52:14 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 16:39:59 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_memory.h>
#include <libft_string.h>
#include <libft_printf.h>
#include <libft_converters.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"

int				load(const char *fname, struct s_map *map)
{
	int			fd;
	char		*line;
	int			c;
	char		*pos;
	int			line_id;

	if (!map)
	{
		ft_error("error: %s: invalid map pointer.\n",
				 fname);
		return (0);
	}
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		ft_error("error: %s: couldn't open file for reading.\n", fname);
		return (0);
	}
	line = NULL;
	if ((c = ft_getline(fd, &line)) > 0)
	{
		pos = ft_strchr(line, 'x');
		if (!pos)
		{
			ft_error("error: %s: couldn't read map format descriptor,\n"
					 "should be widthxheight, got: %s\n", fname, line);
			return (0);
		}
		map_reset(map);
		map->width = ft_atoi(line);
		map->height = ft_atoi(pos + 1);
#ifdef _DEBUG
		ft_printf("Info: Loading %ix%i map.\n", map->width, map->height);
#endif
		map->data = (char*)ft_memalloc(
			sizeof(char) * (map->width * map->height + 1));
		if (!map->data)
		{
			ft_error("error: %s: couldn't allocate %u bytes for map datas.\n",
					 fname, (unsigned)map->width * (unsigned)map->height);
			return (0);
		}
	}
	line = NULL;
	if ((c = ft_getline(fd, &line)) > 0)
	{
		map->scale = ft_atoi(line);
		ft_printf("Info: map scaling is %i.\n", (int)map->scale);
	}
	line_id = 0;
	while ((c = ft_getline(fd, &line)) > 0)
	{
#ifdef _DEBUG
		ft_printf("Info: %i: %s (width: %i)\n", line_id, line, ft_strlen(line));
#endif
		if (ft_strlen(line) != (size_t)map->width)
		{
			ft_error("error: %s: incorrect map width, should be %i got %u.\n",
					 map->width, (unsigned)ft_strlen(line));
			ft_error("\t-> line %i will be truncated.\n", line_id);
		}
		ft_strncpy(map->data + (line_id * map->width), line, map->width);
		ft_strdel(&line);
		line_id++;
	}
	close(fd);
	return (1);
}
