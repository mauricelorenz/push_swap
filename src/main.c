/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:16:47 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/16 18:20:12 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	test_output(t_stack *stack); // ##################################### REMOVE

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_a_orig;

	if (argc < 2)
		return (1);
	if (!arguments_valid(argc, argv))
		return (ft_putendl_fd("Error", 2), 2);
	if (already_sorted(argc, argv))
		return (0);
	stack_a = populate_stack(argc, argv);
	if (!stack_a)
		return (3);
	stack_a_orig = stack_a;
	test_output(stack_a);
	sab(&stack_a, 'a');
	test_output(stack_a);
	stack_clear(&stack_a_orig);
	return (0);
}

static void	test_output(t_stack *stack) // ##################################### REMOVE
{
	while (stack)
	{
		ft_printf("%i\n", stack->member);
		stack = stack->next;
	}
}
