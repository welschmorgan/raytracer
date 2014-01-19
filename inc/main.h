/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 00:40:24 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 16:04:02 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
# define VERSION_MAJOR 0
# define VERSION_MINOR 0
# define VERSION_BUILD 1
# define VERSION_REV 0
# define VERSION_STATUS_SHORT "a"
# define VERSION_STATUS_LONG "alpha"

/*
** Main entry point
*/
int				main(int ac, char **argv);

/*
** Exits the application displaying a message on STDERR
*/
void			die(const char *msg);

/*
** Application Name setter / getter
*/
char	*get_app_title(void);
char	*get_app_name(void);
char	*get_app_version(int long_format);
void	set_app_name(const char *name);

struct	s_mlx_env;
int		event_handler(struct s_mlx_env *env, int a, int b, int c);

#endif /* !MAIN_H */
