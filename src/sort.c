/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:36:54 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/30 19:55:21 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_btoa(t_stack **stack_a, t_stack **stack_b, int max_rank);
static int	get_rank_pos(t_stack *stack, int rank);

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	max_rank;
	int	i;
	int	range;

	max_rank = set_rank(*stack_a);
	range = (max_rank + 1) / 22 + 8;
	i = 0;
	while (*stack_a)
	{
		if (((*stack_a)->rank) <= i)
		{
			pab(stack_b, stack_a, 'b');
			rab(stack_b, 'b');
			i++;
		}
		else if (((*stack_a)->rank) <= i + range)
		{
			pab(stack_b, stack_a, 'b');
			i++;
		}
		else
			rab(stack_a, 'a');
	}
	sort_btoa(stack_a, stack_b, max_rank);
}

static void	sort_btoa(t_stack **stack_a, t_stack **stack_b, int max_rank)
{
	int	rank_pos;

	while (*stack_b)
	{
		rank_pos = get_rank_pos(*stack_b, max_rank);
		if (rank_pos <= max_rank / 2)
			while (((*stack_b)->rank) != max_rank)
				rab(stack_b, 'b');
		else
			while (((*stack_b)->rank) != max_rank)
				rrab(stack_b, 'b');
		pab(stack_a, stack_b, 'a');
		max_rank--;
	}
}

static int	get_rank_pos(t_stack *stack, int rank)
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
