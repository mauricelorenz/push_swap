/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:16:47 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/15 00:08:47 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	while (stack_a)
	{
		ft_printf("%i\n", stack_a->member);
		stack_a = stack_a->next;
	}
	stack_clear(&stack_a_orig);
	return (0);
}
