/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:07:40 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/08 10:12:19 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		curr_next = (*lst)->next;
		free(*lst);
		*lst = curr_next;
	}
	*lst = 0;
}
