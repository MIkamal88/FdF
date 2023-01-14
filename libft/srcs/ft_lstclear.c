/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:34:26 by mshehata          #+#    #+#             */
/*   Updated: 2022/11/25 11:32:27 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*nxt_lst;

	if (!del || !lst)
		return ;
	current = *lst;
	while (current)
	{
		nxt_lst = current->next;
		ft_lstdelone(current, del);
		current = nxt_lst;
	}
	*lst = NULL;
}
