/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:24:05 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/16 23:13:05 by mlorenz          ###   ########.fr       */
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
		ft_putendl_fd("ra", 1);
	else if (ab == 'b')
		ft_putendl_fd("rb", 1);
	return ;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a, 's');
	rab(stack_b, 's');
	ft_putendl_fd("rr", 1);
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
		ft_putendl_fd("rra", 1);
	else if (ab == 'b')
		ft_putendl_fd("rrb", 1);
	return ;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a, 's');
	rrab(stack_b, 's');
	ft_putendl_fd("rrr", 1);
	return ;
}

static t_stack	*stack_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}
