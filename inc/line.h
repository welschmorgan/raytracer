/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:55:37 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 21:57:00 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "vec2.h"

typedef struct	s_line
{
	t_vec2		start;
	t_vec2		end;
	int			color;
}				t_line;

t_line			*line_init(t_line *l);
t_line			*line_set(t_line *l, t_vec2 *start, t_vec2 *end, int col);


#endif /* !LINE_H */
