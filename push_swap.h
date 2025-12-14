/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:27 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/14 23:51:08 by mlorenz          ###   ########.fr       */
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
	int				member;
	struct s_stack	*next;
}					t_stack;
t_stack	*populate_stack(int argc, char **argv);
void	stack_clear(t_stack **stack);
#endif
