/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:29 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/04 15:50:23 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	arguments_valid(int argc, char **argv)
{
	char	*arg_ptr;
	long	arg_nbr;

	argv++;
	while (argc-- > 1)
	{
		arg_ptr = *argv;
		while (*arg_ptr)
		{
			if (!ft_isdigit(*arg_ptr) && *arg_ptr != '-')
				return (0);
			arg_ptr++;
		}
		arg_nbr = ft_atol(*argv);
		if (arg_nbr < INT_MIN || arg_nbr > INT_MAX)
			return (0);
		
		argv++;
	}
	return (1);
}

