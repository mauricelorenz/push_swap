/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 13:03:56 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/09 20:06:59 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	get_instruction_list(t_list **instruction_list);
static int	execute_instruction(t_stack **stack_a,
				t_stack **stack_b, char *instruction);
static void	delete_instruction(void *instruction);

int	check_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_list	*instruction_list;
	t_list	*instruction_ptr;

	instruction_list = NULL;
	if (!get_instruction_list(&instruction_list))
		return (ft_lstclear(&instruction_list, delete_instruction), -1);
	instruction_ptr = instruction_list;
	while (instruction_ptr)
	{
		if (!execute_instruction(stack_a, stack_b,
				(char *)instruction_ptr->content))
			return (ft_lstclear(&instruction_list,
					delete_instruction), write(2, "Error\n", 6), 2);
		instruction_ptr = instruction_ptr->next;
	}
	if (is_sorted(stack_a) && !(*stack_b))
		return (ft_lstclear(&instruction_list,
				delete_instruction), write(1, "OK\n", 3), 0);
	return (ft_lstclear(&instruction_list,
			delete_instruction), write(1, "KO\n", 3), 1);
}

static int	get_instruction_list(t_list **instruction_list)
{
	char	*new_instruction;
	t_list	*new_node;

	while (1)
	{
		new_instruction = get_next_line(0);
		if (!new_instruction)
			break ;
		new_node = ft_lstnew(new_instruction);
		if (!new_node)
			return (0);
		ft_lstadd_back(instruction_list, new_node);
	}
	return (1);
}

static int	execute_instruction(t_stack **stack_a,
	t_stack **stack_b, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		sab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pab(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pab(stack_b, stack_a, 'c');
	else if (!ft_strncmp(instruction, "ra\n", 3))
		rab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rrab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b, 'c');
	else
		return (0);
	return (1);
}

static void	delete_instruction(void *instruction)
{
	free(instruction);
	instruction = NULL;
}
