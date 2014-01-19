/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_title.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 05:53:22 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 05:56:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
#include <libft_printf.h>

char		*get_app_title(void)
{
	static char		buffer[142] = {0};
	char			*ptr;

	if (buffer[0])
		return (buffer);
	ptr = buffer;
	ft_snprintf(&ptr, 142, "%s v%s", get_app_name()
#ifdef _DEBUG
				, get_app_version(1)
#else
				, get_app_version(0)
#endif
);
	return (buffer);
}
