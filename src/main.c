/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 05:32:23 by mwelsch           #+#    #+#             */
/*   Updated: 2014/02/14 19:06:24 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "raytracer.h"
#include <stdlib.h>
#include <libft_converters.h>
#include <libft_string.h>
#include <libft_printf.h>

int						main(int ac, char **av)
{
	t_engine			engine;
	unsigned int		width = 512;
	unsigned int		height = 512;
	static char			title[80] = {"RTV1"};

	if (ac > 3)
		ft_strncpy(title, av[3], 80);
	if (ac > 2)
		height = ft_atoi(av[2]);
	if (ac > 1)
		width = ft_atoi(av[1]);
	engine_init(&engine, width, height, title);
	mlx_loop(engine.core);
	return (RTE_SUCCESS);
}
