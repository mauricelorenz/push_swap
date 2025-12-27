/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:27 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/27 16:30:16 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

int		main(int argc, char **argv);
int		already_sorted(int argc, char **argv);
int		arguments_valid(int argc, char **argv);
typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}					t_stack;
t_stack	*populate_stack(int argc, char **argv);
t_stack	*stack_last(t_stack *stack);
void	stack_clear(t_stack **stack);
void	sab(t_stack **stack, char ab);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pab(t_stack **stack_dst, t_stack **stack_src, char ab);
void	rab(t_stack **stack, char ab);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrab(t_stack **stack, char ab);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	set_rank(t_stack *stack);
int		stack_len(t_stack *stack);
int		get_min(t_stack *stack_ptr);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
#endif
