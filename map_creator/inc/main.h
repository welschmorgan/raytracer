/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:51:52 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/18 20:18:10 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

struct			s_map;

int				usage(const char *app_name);
int				load(const char *file_name, struct s_map *map);
char			*get_output_name(const char *input_name);

#endif /* !MAIN_H */
