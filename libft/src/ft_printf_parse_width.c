/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_width.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 15:13:48 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/12 16:04:04 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_converters.h>
#include <libft_memory.h>
#include <libft_string.h>
#include "libft_printf.h"

int					ft_printf_parse_width(char **fmt)
{
	char			buffer[FT_PRINTF_MAX_WIDTH + 1];
	unsigned char	counter;
	int				ret;

	ret = 0;
	counter = 0;
	ft_memset((void*)buffer, 0, FT_PRINTF_MAX_WIDTH);
	while (fmt && *fmt && **fmt
		   && ft_isdigit(**fmt)
		   && counter < FT_PRINTF_MAX_WIDTH)
		buffer[counter++] = *((*fmt) ++);
	while (fmt && *fmt && **fmt && ft_isdigit(**fmt))
		(*fmt) ++;
	buffer[counter] = '\0';
	ret = ft_atoi(buffer);
	if (ret < 0)
		ret = 0;
	return (ret);
}
