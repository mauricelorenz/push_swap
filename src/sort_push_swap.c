/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:33:49 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/16 22:06:00 by mlorenz          ###   ########.fr       */
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

void	pab(t_stack **stack_dst, t_stack **stack_src, char ab)
{
	t_stack	*src_head;

	if (*stack_src)
	{
		src_head = *stack_src;
		*stack_src = (*stack_src)->next;
		src_head->next = *stack_dst;
		*stack_dst = src_head;
	}
	if (ab == 'a')
		ft_putendl_fd("pa", 1);
	else if (ab == 'b')
		ft_putendl_fd("pb", 1);
	return ;
}
