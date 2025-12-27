/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:36:54 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/27 16:30:16 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_rank(t_stack *stack)
{
	int		i;
	int		len;
	int		min;
	t_stack	*stack_ptr;

	i = 0;
	len = stack_len(stack);
	while (i < len)
	{
		stack_ptr = stack;
		min = get_min(stack);
		while (stack_ptr)
		{
			if (stack_ptr->value == min)
				stack_ptr->rank = i;
			stack_ptr = stack_ptr->next;
		}
		i++;
	}
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if ((stack->rank == -1) && (stack->value < min))
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

// void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
// {
// }
