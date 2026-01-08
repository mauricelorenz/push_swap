/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:36:54 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/08 09:56:20 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_tiny(t_stack **stack_a, int offset);
static void	sort_small(t_stack **stack_a, t_stack **stack_b, int max_rank);
static void	sort_big(t_stack **stack_a, t_stack **stack_b, int max_rank);
static void	sort_btoa(t_stack **stack_a, t_stack **stack_b, int max_rank);

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
		sort_tiny(stack_a, 0);
		return ;
	}
	if (max_rank <= 4)
	{
		sort_small(stack_a, stack_b, max_rank);
		return ;
	}
	sort_big(stack_a, stack_b, max_rank);
}

static void	sort_tiny(t_stack **stack_a, int offset)
{
	if ((*stack_a)->rank == 2 + offset)
		rab(stack_a, 'a');
	else if (((*stack_a)->rank == 0 + offset)
		|| ((*stack_a)->next->next->rank == 0 + offset))
		rrab(stack_a, 'a');
	if ((*stack_a)->rank == 1 + offset)
		sab(stack_a, 'a');
	return ;
}

static void	sort_small(t_stack **stack_a, t_stack **stack_b, int max_rank)
{
	int	i;
	int	offset;
	int	rank_pos;

	i = 0;
	offset = max_rank - 2;
	while (i < offset)
	{
		rank_pos = get_rank_pos(*stack_a, i);
		if (rank_pos <= max_rank / 2)
			while (((*stack_a)->rank) != i)
				rab(stack_a, 'a');
		else
			while (((*stack_a)->rank) != i)
				rrab(stack_a, 'a');
		if (is_sorted(stack_a) && !(*stack_b))
			return ;
		pab(stack_b, stack_a, 'b');
		i++;
	}
	if (!is_sorted(stack_a))
		sort_tiny(stack_a, offset);
	while (*stack_b)
		pab(stack_a, stack_b, 'a');
}

static void	sort_big(t_stack **stack_a, t_stack **stack_b, int max_rank)
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
