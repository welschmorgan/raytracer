/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:27:41 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/30 15:31:36 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isempty(char const	*str)
{
	while (str && *str && ft_isspace(*str))
		str ++;
	return ((*str == '\0') ? TRUE : FALSE);
}
