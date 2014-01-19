/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 23:43:55 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/18 23:59:44 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <fcntl.h>
#include <unistd.h>

int		read_file(const char *name)
{
	int				fd;
	char			*buf;
	unsigned int	line_id;

	line_id = 0;
	buf = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (ft_getline(fd, &buf) > 0)
	{
		ft_printf("Line(%u): %s\n",
				  line_id, buf);
/*		ft_strdel(&buf);*/
		line_id ++;
	}
	close(fd);
	return (1);
}

int	usage(const char *name)
{
	return (ft_printf("usage: %s file\n", name));
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (usage(av[0]));
	return (read_file(av[1]));
}
