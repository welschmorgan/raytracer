/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 04:21:13 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/14 04:46:11 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft_printf.h>
#include <libft_string.h>
#include <libft_converters.h>

int					get_float_decimal(float f, int precision)
{
	float		cur;

	cur = (((float)f) - (float)((int)f));
	while (precision--)
		cur *= 10.0f;
	return (int)cur;
}

void				ft_vsnprintf_float(t_vsnprintf_env *env,
									   va_list args)
{
	float		f;
	int			dec;
	int			intg;
	size_t		len;

	f = (float)va_arg(args, double);
	if (!env)
		return ;
	dec = get_float_decimal(f, 6);
	intg = (int)f;
	if (dec >= 0.51f)
		intg += 1;
	len = ft_number_length((unsigned long)intg, 10);
	if (intg < 0)
	{
		*env->offset++ = '-';
	}
	ft_strncpy(env->offset, ft_ntoa((unsigned long)dec, 10), env->max);
	env->offset += len;
	env->counter += len;
}
