/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:30 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 10:12:15 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
#ifdef FT_DEBUG_LINKED_LISTS
	ft_printf("list %p: add_front %p\n", alst ? *alst : NULL, new);
#endif
	if (alst && *alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}
