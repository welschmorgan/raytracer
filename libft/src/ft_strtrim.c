/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 21:27:03 by mwelsch           #+#    #+#             */
/*   Updated: 2013/11/30 15:11:41 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrot(char *str, size_t num_rots)
{
	char	*ptr;

	if (!num_rots)
		return (str);
	while (num_rots)
	{
		ptr = str;
		while (ptr && *ptr)
		{
			*ptr = *(ptr + 1);
			ptr ++;
		}
		num_rots --;
	}
	return (str);
}

char	*ft_strltrim(char *str, char const *separators)
{
	char	*ptr;

	while (str && ft_isanyof(*str, separators))
	{
		ptr = str;
		while (ptr && *ptr)
		{
			*ptr = *(ptr + 1);
			ptr ++;
		}
	}
	return (str);
}

char	*ft_strrtrim(char *str, char const *separators)
{
	char	*p_end;
	char	*p_start;
	size_t	len;

	len = ft_strlen(str);
	if (!len)
		return (NULL);
	p_end = str + (len - 1);
	p_start = str;
	while (p_start && p_end >= p_start&& ft_isanyof(*p_end, separators))
	{
		*p_end = '\0';
		p_end --;
	}
	return (str);
}

char	*ft_strtrim(char const *s)
{
	char				*ret;
	char const			seps[] = " \n\t";
	size_t				len;

	len = ft_strlen(s);
	if (!len)
		return (NULL);
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	return (ft_strltrim(ft_strrtrim(ret, seps), seps));
}
