/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:23:30 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/09 14:49:13 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*stack_new(int value);
static void		stack_add_back(t_stack **stack, t_stack *new);

t_stack	*populate_stack(int argc, char **argv)
{
	t_stack	*my_stack;
	t_stack	*new_node;

	my_stack = NULL;
	argv++;
	while (argc-- > 1)
	{
		new_node = stack_new(ft_atoi(*argv));
		if (!new_node)
			return (stack_clear(&my_stack), NULL);
		stack_add_back(&my_stack, new_node);
		argv++;
	}
	return (my_stack);
}

static t_stack	*stack_new(int value)
{
	t_stack	*my_stack;

	my_stack = malloc(sizeof(t_stack));
	if (!my_stack)
		return (NULL);
	my_stack->value = value;
	my_stack->rank = -1;
	my_stack->next = NULL;
	return (my_stack);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*curr_next;

	if (!stack)
		return ;
	while (*stack)
	{
		curr_next = (*stack)->next;
		free(*stack);
		*stack = curr_next;
	}
	*stack = NULL;
}

static void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
		*stack = new;
	else
		stack_last(*stack)->next = new;
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
