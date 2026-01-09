/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:33:49 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/09 20:08:43 by mlorenz          ###   ########.fr       */
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
		write(1, "sa\n", 3);
	else if (ab == 'b')
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b, char s)
{
	sab(stack_a, 's');
	sab(stack_b, 's');
	if (s == 's')
		write(1, "ss\n", 3);
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
		write(1, "pa\n", 3);
	else if (ab == 'b')
		write(1, "pb\n", 3);
	return ;
}
