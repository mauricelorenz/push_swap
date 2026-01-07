/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:36:54 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/07 12:51:05 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_small_n(t_stack **stack_a, t_stack **stack_b, int max_rank);
static void	sort_stacks(t_stack **stack_a, t_stack **stack_b, int max_rank);
static void	sort_btoa(t_stack **stack_a, t_stack **stack_b, int max_rank);
static int	get_rank_pos(t_stack *stack, int rank);

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_rank;

	max_rank = set_rank(*stack_a);
	if (max_rank == 1)
	{
		sab(stack_a, 'a');
		return ;
	}
	if (max_rank == 2)
	{
		if ((*stack_a)->value == 2)
			rab(stack_a, 'a');
		else if ((*stack_a)->value == 0)
			rrab(stack_a, 'a');
		if ((*stack_a)->value == 1)
			sab(stack_a, 'a');
		return ;
	}
	if (max_rank == 4)
	{
		sort_small_n(stack_a, stack_b, max_rank);
		return ;
	}
	sort_stacks(stack_a, stack_b, max_rank);
}

static void	sort_small_n(t_stack **stack_a, t_stack **stack_b, int max_rank)
{
	t_stack	**stack_a_ptr;

	(void)stack_b;
	(void)max_rank;
	while (1)
	{
		stack_a_ptr = stack_a;
		while (1)
		{
			if (!(*stack_a_ptr)->next)
				return ;
			if ((*stack_a_ptr)->value > (*stack_a_ptr)->next->value)
				break;
			*stack_a_ptr = (*stack_a_ptr)->next;
		}
		if ((*stack_a_ptr)->value > (*stack_a_ptr)->next->value)
			sab(stack_a, 'a');
		rab(stack_a, 'a');
	}
}

static void	sort_stacks(t_stack **stack_a, t_stack **stack_b, int max_rank)
{
	int	i;
	int	range;

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
