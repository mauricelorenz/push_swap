/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:24:05 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/09 20:09:38 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*stack_second_last(t_stack *stack);

void	rab(t_stack **stack, char ab)
{
	t_stack	*tail;

	if (*stack && (*stack)->next)
	{
		tail = stack_last(*stack);
		tail->next = *stack;
		*stack = (*stack)->next;
		tail->next->next = NULL;
	}
	if (ab == 'a')
		write(1, "ra\n", 3);
	else if (ab == 'b')
		write(1, "rb\n", 3);
	return ;
}

void	rr(t_stack **stack_a, t_stack **stack_b, char r)
{
	rab(stack_a, 'r');
	rab(stack_b, 'r');
	if (r == 'r')
		write(1, "rr\n", 3);
	return ;
}

void	rrab(t_stack **stack, char ab)
{
	t_stack	*head;
	t_stack	*new_tail;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		new_tail = stack_second_last(*stack);
		*stack = new_tail->next;
		(*stack)->next = head;
		new_tail->next = NULL;
	}
	if (ab == 'a')
		write(1, "rra\n", 4);
	else if (ab == 'b')
		write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, char r)
{
	rrab(stack_a, 'r');
	rrab(stack_b, 'r');
	if (r == 'r')
		write(1, "rrr\n", 4);
	return ;
}

static t_stack	*stack_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
