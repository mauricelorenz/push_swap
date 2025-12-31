/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 13:03:56 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/31 16:21:17 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <string.h> // ############################################# REMOVE
#include <stdio.h> // ############################################# REMOVE

void	free_null_list(char **list);
int		is_sorted(t_stack **stack_a, t_stack **stack_b);
char	**get_instruction_list(void);
int		execute_instruction(t_stack **stack_a, t_stack **stack_b, char *instruction);

int	check_sorting(t_stack **stack_a, t_stack **stack_b)
{
	char	**instruction_list;
	char	**instruction_list_ptr;

	instruction_list = get_instruction_list();
	instruction_list_ptr = instruction_list;
	while(*instruction_list_ptr)
	{
		if (!execute_instruction(stack_a, stack_b, *instruction_list_ptr))
			return(free_null_list(instruction_list), ft_putendl_fd("Error", 2), 2);
		instruction_list_ptr++;
	}
	free_null_list(instruction_list);
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
	if (!ft_strncmp(instruction, "sa", 3))
		sab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "sb", 3))
		sab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "ss", 3))
		ss(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "pa", 3))
		pab(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "pb", 3))
		pab(stack_b, stack_a, 'c');
	else if (!ft_strncmp(instruction, "ra", 3))
		rab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "rb", 3))
		rab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "rr", 3))
		rr(stack_a, stack_b, 'c');
	else if (!ft_strncmp(instruction, "rra", 4))
		rrab(stack_a, 'c');
	else if (!ft_strncmp(instruction, "rrb", 4))
		rrab(stack_b, 'c');
	else if (!ft_strncmp(instruction, "rrr", 4))
		rrr(stack_a, stack_b, 'c');
	else
		return (0);
	return (1);
}

char	**get_instruction_list(void)
{
	int		i;
	ssize_t	bytes_read;
	char	buf[BUFFER_SIZE + 1];
	char	*buf_ptr;
	char	*instructions;
	char	**instruction_list;

	i = 1;
	buf_ptr = buf;
	instructions = NULL;
	while (1)
	{
		bytes_read = read(0, buf_ptr, BUFFER_SIZE);
		*(buf_ptr + bytes_read) = '\0';
		if (bytes_read == -1)
			return (0);
		instructions = realloc(instructions, (i * BUFFER_SIZE) + 1); // ############################################# REMOVE
		if (i == 1)
			*instructions = '\0';
		strcat(instructions, buf_ptr); // ############################################# REMOVE
		if (bytes_read < BUFFER_SIZE)
			break;
		i++;
	}
	instruction_list = ft_split(instructions, '\n');
	free(instructions);
	return (instruction_list);
}
