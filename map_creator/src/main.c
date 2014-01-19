/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:57:44 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 15:47:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <stdlib.h>
#include "map.h"
#include "main.h"

int				main(int ac, char **av)
{
	t_map		m;

	if (ac < 2 || ac > 3)
		return (usage(av[0]));
	map_init(&m);
#ifdef _DEBUG
	ft_printf("Input file: %s\n", av[1]);
	ft_printf("Output file: %s\n", ac == 2 ? get_output_name(av[1]) : av[2]);
#endif
	if (!load(av[1], &m))
		return (EXIT_FAILURE);
	if (ac == 2)
		map_save(get_output_name(av[1]), &m);
	else
		map_save(av[2], &m);
	return (EXIT_SUCCESS);
}
