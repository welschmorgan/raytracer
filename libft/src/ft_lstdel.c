/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 22:49:22 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 10:14:49 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p_it;
	t_list	*p_next;

#ifdef FT_DEBUG_LINKED_LISTS
	ft_printf("list %p: del\n", alst ? *alst : NULL);
#endif
	if (!alst || !*alst)
		return ;
	p_it = (*alst);
	p_next = (*alst)->next;
	ft_lstdelone(&p_it, del);
	if (p_next)
		ft_lstdel(&p_next, del);
	*alst = NULL;
}
