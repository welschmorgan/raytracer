/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 03:00:54 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 15:10:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include <libft_memory.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int			main(int ac, char **av)
{
	char	*buf;
	int		fd;

	(void)ac;
	(void)av;
	buf = NULL;
	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
	}
	while (getln(fd, &buf) > 0)
	{
		printf("line: %s\n", buf);
		ft_strdel(&buf);
	}
	if (ac == 2)
		close(fd);
	return (0);
}
