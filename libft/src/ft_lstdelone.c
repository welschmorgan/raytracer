/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:44:58 by mwelsch           #+#    #+#             */
/*   Updated: 2013/12/28 10:18:19 by mwelsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t s))
{
	t_list * ptr;

#ifdef FT_DEBUG_LINKED_LISTS
	ft_printf("list %p: delone\n", alst ? *alst : NULL);
#endif
	if (!alst || !*alst)
		return ;
	ptr = *alst;
	if (ptr->content)
	{
#ifdef FT_DEBUG_LINKED_LISTS
		ft_printf("\tdeleting content %p\n", ptr->content);
#endif
		del(ptr->content, ptr->content_size);
	}
	ft_memdel((void**)alst);
}
