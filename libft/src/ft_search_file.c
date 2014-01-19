/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 08:08:29 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/12 15:08:47 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft_file.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <dirent.h>

t_search_params		*ft_search_set_params(t_search_params *p,
										  const char *dir,
										  int access,
										  t_bool recursive)
{
	if (!p)
		return (p);
	ft_strncpy(p->dir, dir, 1042);
	p->access_mode = access;
	p->recursive = recursive;
	return (p);
}

static char			*handle_dir(const char *pattern,
								t_search_params *params,
								struct dirent *ent,
								t_bool print_errors)
{
	char			*path;
	struct stat		stat;

	path = ft_path_add(params->dir ? params->dir : ".", ent->d_name, &path);
	if (ft_file_access(path, params->access_mode)
		&& ft_strequ(pattern, ent->d_name))
	{
		return (ft_strdup(path));
	}
	lstat(path, &stat);
	if (!ft_strequ(ent->d_name, ".") && !ft_strequ(ent->d_name, ".."))
	{
		if (S_ISDIR(stat.st_mode) && params->recursive)
			return (ft_search_file(pattern, params, print_errors));
		else
		{
#ifdef FT_DEBUG_FILESYSTEM
			ft_error("%s: %s: file '%s'\n",
					 __FUNCTION__,
					 "readdir",
					 path);
#endif
		}
	}
	return (NULL);
}

char				*ft_search_file(const char *pattern,
									t_search_params *params,
									t_bool print_errors)
{
	struct dirent	*ent;
	DIR				*handle;
	char			*path;

	if (!pattern || !params)
		return (NULL);
	if (!(handle = opendir(params->dir)))
	{
#if defined(FT_DEBUG) && defined(FT_DEBUG_FILESYSTEM)
		ft_error("%s: could not open dir '%s'\n", __FUNCTION__, params->dir);
#endif
		return (NULL);
	}
	while (handle && (ent = readdir(handle))  != NULL)
	{
		if ((path = handle_dir(pattern, params, ent, print_errors)))
			return (path);
	}
	if (handle)
		closedir(handle);
	return (NULL);
}
