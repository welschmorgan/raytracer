/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 00:39:58 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 01:35:32 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <libft_printf.h>
#include <stdlib.h>

void			die(const char *msg)
{
	ft_error("error: %s\n", msg);
	exit (EXIT_FAILURE);
}
