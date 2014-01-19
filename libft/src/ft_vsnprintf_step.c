/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 03:23:07 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 05:33:14 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft_printf.h>
#include <libft_string.h>

void				ft_vsnprintf_step(t_vsnprintf_env *env,
									  va_list args)
{
	char	c;

	if (!env)
		return ;
	c = *env->format;
	if (c == 's' || c == 'S')
		ft_vsnprintf_string(env, args, ft_isupper(c));
	else if (c == 'i' || c == 'l' || c == 'd')
		ft_vsnprintf_signed(env, args, 10);
	else if (c == 'f')
		ft_vsnprintf_float(env, args);
	else if (c == 'u')
		ft_vsnprintf_unsigned(env, args, 10);
	else if (c == 'c' || c == 'C')
		ft_vsnprintf_char(env, args, ft_isupper(c));
	else if (c == 'p' || c == 'P')
	{
		ft_strncpy(env->offset, "0x", env->max);
		env->offset += 2;
		env->counter += 2;
		ft_vsnprintf_hexa(env, args, ft_isupper(c), 1);
	}
	else if (c == 'x' || c == 'X')
		ft_vsnprintf_hexa(env, args, ft_isupper(c), 0);
	else
	{
		*env->offset = c;
		env->offset++;
		env->counter++;
	}
	env->format++;
}
