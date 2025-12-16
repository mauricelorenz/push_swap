/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:33:49 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/16 18:21:37 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sab(t_stack **stack, char ab)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		*stack = (*stack)->next;
		tail = (*stack)->next;
		(*stack)->next = head;
		(*stack)->next->next = tail;
	}
	if (ab == 'a')
		ft_putendl_fd("sa", 1);
	else if (ab == 'b')
		ft_putendl_fd("sb", 1);
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sab(stack_a, 's');
	sab(stack_b, 's');
	ft_putendl_fd("ss", 1);
	return ;
}
