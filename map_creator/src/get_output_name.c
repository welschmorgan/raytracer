/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 20:17:15 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 15:49:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_string.h>
#include "main.h"

char			*get_output_name(const char *input_name)
{
	static char	buffer[260];
	char		*pos;

	if (!input_name)
		return (NULL);
	ft_strncpy(buffer, input_name, 260);
	pos = ft_strchr(buffer, '.');
	if (pos)
		ft_strncpy(pos + 1, "map", 260);
	else if (ft_strlen(buffer) >= 4)
		ft_strncpy(buffer + (ft_strlen(buffer) - 4), ".map", 260);
	else
		ft_strncpy(buffer, "out.map", 260);
	return (buffer);
}
