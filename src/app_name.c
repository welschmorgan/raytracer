/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 01:44:47 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 03:37:37 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
#include <libft_string.h>

char	*get_app_name(void)
{
	static char		g_app_name[80];

	return (g_app_name);
}

void	set_app_name(const char *name)
{
	ft_strncpy(get_app_name(), name, 80);
}
