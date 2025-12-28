/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:29 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/28 19:09:07 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_unique(char *arg_ptr, char **argv);

int	already_sorted(int argc, char **argv)
{
	argv++;
	while (argc-- > 2)
	{
		if (ft_atoi(*argv) > ft_atoi(*(argv + 1)))
			return (0);
		argv++;
	}
	return (1);
}

int	arguments_valid(int argc, char **argv)
{
	char	*arg_ptr;
	char	**argv_ptr;
	long	arg_long;

	argv++;
	argv_ptr = argv;
	while (argc-- > 1)
	{
		arg_ptr = *argv_ptr;
		while (*arg_ptr)
		{
			if (!ft_isdigit(*arg_ptr) && *arg_ptr != '-')
				return (0);
			arg_ptr++;
		}
		arg_long = ft_atol(*argv_ptr);
		if (arg_long < INT_MIN || arg_long > INT_MAX)
			return (0);
		if (!is_unique(*argv_ptr, argv))
			return (0);
		argv_ptr++;
	}
	return (1);
}

static int	is_unique(char *arg_ptr, char **argv)
{
	char	**argv_curr;
	int		arg_int;

	argv_curr = argv;
	arg_int = ft_atoi(arg_ptr);
	while (*argv_curr < arg_ptr)
	{
		if (arg_int == ft_atoi(*argv_curr))
			return (0);
		argv_curr++;
	}
	return (1);
}
