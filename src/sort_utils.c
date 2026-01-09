/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:53:13 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/09 14:15:37 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*stack_a_ptr;

	stack_a_ptr = *stack_a;
	while ((stack_a_ptr)->next)
	{
		if ((stack_a_ptr)->value > (stack_a_ptr)->next->value)
			return (0);
		stack_a_ptr = (stack_a_ptr)->next;
	}
	return (1);
}

int	get_rank_pos(t_stack *stack, int rank)
{
	int	i;

	i = 0;
	while (stack)
	{
		if ((stack->rank) == rank)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
