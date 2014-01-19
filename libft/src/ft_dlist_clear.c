/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:15:08 by mwelsch           #+#    #+#             */
/*   Updated: 2014/01/19 15:18:29 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_printf.h>
#include <libft_dlist.h>

void	ft_dlist_clear(t_dlist *list, t_dnode_deleter deleter)
{
	t_dnode	*cur;

#ifdef _DEBUG
	ft_printf("Clearing list 0x%x:\n", list);
#endif
	cur = list->tail;
	while (cur != list->head)
	{
		ft_dlist_remove(list, cur, deleter);
		cur = cur->next;
	}
}
