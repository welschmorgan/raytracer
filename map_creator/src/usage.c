/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:51:05 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/18 20:11:34 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
#include <libft_printf.h>

int				usage(const char *app_name)
{
	ft_printf("usage: %s input_file [output_file]\n", app_name);
	return (1);
}
