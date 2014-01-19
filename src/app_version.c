/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_version.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 01:46:48 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 03:39:21 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
#include <libft_string.h>
#include <libft_converters.h>

char		*get_app_version(int long_fmt)
{
	static char		buffer[150] = {0};

	if (!buffer[0])
	{
		ft_strncpy(buffer, ft_ntoa(VERSION_MAJOR, 10), 150);
		ft_strncat(buffer, ".", 150);
		ft_strncat(buffer, ft_ntoa(VERSION_MINOR, 10), 150);
		ft_strncat(buffer, ".", 150);
		ft_strncat(buffer, ft_ntoa(VERSION_BUILD, 10), 150);
		ft_strncat(buffer, ".", 150);
		ft_strncat(buffer, ft_ntoa(VERSION_REV, 10), 150);
		if (long_fmt)
		{
			ft_strncat(buffer, " ", 150);
			ft_strncat(buffer, VERSION_STATUS_LONG, 150);
		}
		else
			ft_strncat(buffer, VERSION_STATUS_SHORT, 150);
	}
	return (buffer);
}
