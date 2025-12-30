/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:53:27 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/30 19:57:01 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	stack_len(t_stack *stack);
static int	get_min(t_stack *stack);

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

static int	stack_len(t_stack *stack)
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

static int	get_min(t_stack *stack)
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
