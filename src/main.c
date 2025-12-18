/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:16:47 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/18 21:54:13 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	stack_b = NULL;
	sort_stacks(&stack_a, &stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}

// static void	test_output(t_stack *stack) // ########################## REMOVE
// {
// 	while (stack)
// 	{
// 		ft_printf("%i\n", stack->member);
// 		stack = stack->next;
// 	}
// }

// int	main(int argc, char **argv) // ################################## REMOVE
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (argc < 2)
// 		return (1);
// 	if (!arguments_valid(argc, argv))
// 		return (ft_putendl_fd("Error", 2), 2);
// 	// if (already_sorted(argc, argv))
// 	// 	return (0);
// 	stack_a = populate_stack(argc, argv);
// 	stack_b = populate_stack(argc, argv);
// 	if (!stack_a || !stack_b)
// 		return (3);
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	test_output(stack_b);
// 	sab(&stack_a, 'a');
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	test_output(stack_b);
// 	pab(&stack_a, &stack_b, 'a');
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	test_output(stack_b);
// 	rab(&stack_a, 'a');
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	test_output(stack_b);
// 	rrab(&stack_b, 'b');
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	test_output(stack_b);
// 	stack_clear(&stack_a);
// 	stack_clear(&stack_b);
// 	return (0);
// }

// int	main(int argc, char **argv) // ################################## REMOVE
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	if (argc < 2)
// 		return (1);
// 	if (!arguments_valid(argc, argv))
// 		return (ft_putendl_fd("Error", 2), 2);
// 	stack_a = populate_stack(argc, argv);
// 	stack_b = NULL;
// 	if (!stack_a)
// 		return (3);
// 	ft_printf("stack_a: %p\n", stack_a);
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	ft_printf("stack_b: %p\n", stack_b);
// 	test_output(stack_b);
// 	pab(&stack_b, &stack_a, 'b');
// 	pab(&stack_b, &stack_a, 'b');
// 	pab(&stack_b, &stack_a, 'b');
// 	pab(&stack_b, &stack_a, 'b');
// 	pab(&stack_b, &stack_a, 'b');
// 	ft_printf("stack_a: %p\n", stack_a);
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	ft_printf("stack_b: %p\n", stack_b);
// 	test_output(stack_b);
// 	pab(&stack_a, &stack_b, 'a');
// 	pab(&stack_a, &stack_b, 'a');
// 	pab(&stack_a, &stack_b, 'a');
// 	pab(&stack_a, &stack_b, 'a');
// 	pab(&stack_a, &stack_b, 'a');
// 	ft_printf("stack_a: %p\n", stack_a);
// 	test_output(stack_a);
// 	ft_putendl_fd("---", 1);
// 	ft_printf("stack_b: %p\n", stack_b);
// 	test_output(stack_b);
// 	stack_clear(&stack_a);
// 	stack_clear(&stack_b);
// 	return (0);
// }
