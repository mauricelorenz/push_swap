/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:27 by mlorenz           #+#    #+#             */
/*   Updated: 2026/01/08 09:55:58 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

int		arguments_valid(int argc, char **argv);
int		already_sorted(int argc, char **argv);
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
void	ss(t_stack **stack_a, t_stack **stack_b, char s);
void	pab(t_stack **stack_dst, t_stack **stack_src, char ab);
void	rab(t_stack **stack, char ab);
void	rr(t_stack **stack_a, t_stack **stack_b, char r);
void	rrab(t_stack **stack, char ab);
void	rrr(t_stack **stack_a, t_stack **stack_b, char r);
int		set_rank(t_stack *stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack **stack_a);
int		get_rank_pos(t_stack *stack, int rank);
#endif
