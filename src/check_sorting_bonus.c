/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 13:03:56 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/05 15:28:03 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <string.h> // ############################################# REMOVE
#include <stdio.h> // ############################################# REMOVE

void	free_null_list(char **list);
int		is_sorted(t_stack **stack_a, t_stack **stack_b);
void	get_instruction_list(char **instruction_list);
int		execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction);

int	check_sorting(t_stack **stack_a, t_stack **stack_b)
{
	// char	*instruction_list[100000];
	// char	**instruction_list_ptr;

	// get_instruction_list(instruction_list);
	// instruction_list_ptr = instruction_list;
	char	*instruction;

	instruction = NULL;
	while(1)
	{
		// printf("%s", *instruction_list_ptr);
		instruction = get_next_line(0);
		if (!instruction)
			break;
		if (!execute_instruction(stack_a, stack_b, instruction))
			return(ft_putendl_fd("Error", 2), 2);
		free(instruction); instruction = NULL; 
		// instruction_list_ptr++;
	}
	// free_null_list(instruction_list);
	if (is_sorted(stack_a, stack_b))
		return (ft_putendl_fd("OK", 1), 0);
	return (ft_putendl_fd("KO", 1), 1);
}

void	free_null_list(char **list)
{
	char **list_ptr;

	list_ptr = list;
	while (*list_ptr)
	{
		free(*list_ptr);
		*list_ptr = NULL;
		list_ptr++;
	}
	free(list);
	list = NULL;
}

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *stack_a_ptr;

	stack_a_ptr = *stack_a;
	while ((stack_a_ptr)->next)
	{
		if ((stack_a_ptr)->value > (stack_a_ptr)->next->value)
			return (0);
		stack_a_ptr = (stack_a_ptr)->next;
	}
	if (*stack_b)
		return (0);
	return (1);
}

int	execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction)
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

// char	**get_instruction_list(void)
// {
// 	int		i;
// 	int		allocated_memory;
// 	char	**instruction_list;
// 	char	**instruction_list_ptr;

// 	i = 0;
// 	allocated_memory = 0;
// 	instruction_list = NULL;
// 	instruction_list_ptr = instruction_list;
// 	while (1)
// 	{
// 		if (i == allocated_memory)
// 		{
// 			instruction_list = realloc(instruction_list, sizeof(char *) * (i + 101));
// 			if (!instruction_list)
// 				return (free_null_list(instruction_list), NULL);
// 			allocated_memory += 100;
// 		}
// 		*instruction_list_ptr = get_next_line(0);
// 		if (!*instruction_list_ptr)
// 			return (instruction_list);
// 		i++;
// 		instruction_list_ptr++;
// 	}
// 	return (instruction_list);
// }

// void	get_instruction_list(char **instruction_list)
// {
// 	int		i;
// 	char	**instruction_list_ptr;

// 	i = 0;
// 	instruction_list_ptr = instruction_list;
// 	while (i < 10000)
// 	{
// 		*instruction_list_ptr = get_next_line(0);
// 		// while (**instruction_list_ptr)
// 		// {
// 		// 	if (**instruction_list_ptr == '\0')
// 		// 		write(1, "\\0", 2);
// 		// 	else if (**instruction_list_ptr == '\n')
// 		// 		write(1, "\\n\n", 3);
// 		// 	else
// 		// 		write(1, *instruction_list_ptr, 1);
// 		// 	(*instruction_list_ptr)++;
// 		// }
// 		if (!*instruction_list_ptr)
// 			return ;
// 		i++;
// 		instruction_list_ptr++;
// 	}
// 	return ;
// }
