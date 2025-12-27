/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:16:47 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/27 16:30:16 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	test_output(t_stack *stack); // ########################## REMOVE

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!arguments_valid(argc, argv))
		return (ft_putendl_fd("Error", 2), 2);
	if (already_sorted(argc, argv))
		return (0);
	stack_a = populate_stack(argc, argv);
	if (!stack_a)
		return (3);
	set_rank(stack_a);
	stack_b = NULL;
	// sort_stacks(&stack_a, &stack_b);
	test_output(stack_a);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

static void	test_output(t_stack *stack) // ########################## REMOVE
{
	while (stack)
	{
		ft_printf("%i: %i\n", stack->rank, stack->value);
		stack = stack->next;
	}
}
