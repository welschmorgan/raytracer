/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:06:29 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/29 08:30:27 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "libft_memory.h"
#include "libft_file.h"

char				*ft_file_basename(const char *path,
									  char **buffer,
									  size_t num)
{
	char			*pos;

	pos = ft_strrchr(path, FT_PATH_SEPARATOR[0]);
	if (!pos)
		return ((char*)path);
	*buffer = NULL;
	return (*buffer = ft_strndup(pos, num));
}

/*
 * Don't forget to free after return
 */
t_file				*ft_file_infos(const char *path, t_file **file)
{
	char			*name;

	if (!*file)
		return (NULL);
	name = NULL;
	ft_file_basename(path, &name, sizeof(t_file));
	(*file)->name = ft_strdup(name);
	lstat(path, &(*file)->infos);
	return (*file);
}

void				ft_file_reset(t_file *file)
{
	if (!file)
		return ;
	if ((file)->name)
		ft_strdel(&(file)->name);
	ft_memset(&file->infos, 0, sizeof(struct stat));
}

void				ft_file_del(t_file **file)
{
	if (!*file)
		return ;
	ft_file_reset(*file);
	ft_memdel((void**)file);
}

char				*ft_path_add(const char *a, const char *b, char **buff)
{
	t_bool		sepra;
	static char	buf[FT_BUF_MAX] = {0};

	(void)buff;
	if (!a)
		return (NULL);
	sepra = (a
			 && ft_strlen(a)
			 && (a[ft_strlen(a) - 1]
				 == FT_PATH_SEPARATOR[0]));
	ft_memset(buf, '\0', FT_BUF_MAX);
	ft_strcpy(buf, a);
	if (!sepra)
		ft_strncat(buf, FT_PATH_SEPARATOR, FT_BUF_MAX);
	if (b)
		ft_strncat(buf, b, FT_BUF_MAX);
	return (buf);
}
