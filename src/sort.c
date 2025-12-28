/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:36:54 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/28 18:08:01 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_rank(t_stack *stack)
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
	return (i - 1);
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

int	get_max_rank_bits(int max_rank)
{
	int	i;

	i = 0;
	while (max_rank)
	{
		max_rank >>= 1;
		i++;
	}
	return (i);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	max_rank;
	int	max_rank_bits;

	max_rank = set_rank(*stack_a);
	max_rank_bits = get_max_rank_bits(max_rank);
	i = 0;
	while (i < max_rank_bits)
	{
		j = 0;
		while (j < max_rank)
		{
			if (((*stack_a)->rank >> i) & 1)
				rab(stack_a, 'a');
			else
				pab(stack_b, stack_a, 'b');
			j++;
		}
		while (*stack_b)
			pab(stack_a, stack_b, 'a');
		i++;
	}
}
