/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:50:11 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/31 16:15:58 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!arguments_valid(argc, argv))
		return (ft_putendl_fd("Error", 2), 2);
	// if (already_sorted(argc, argv))
	// 	return (0);
	stack_a = populate_stack(argc, argv);
	if (!stack_a)
		return (3);
	stack_b = NULL;
	check_sorting(&stack_a, &stack_b);
	printf("%p %p\n", stack_a, stack_b);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}