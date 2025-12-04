/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:16:47 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/04 15:50:16 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (!arguments_valid(argc, argv))
		return (write(2, "Error\n", 6), 2);
	else
		ft_printf("all args valid!\n");
	ft_printf("%s %s %s\n", argv[1], argv[2], argv[3]);
	return (0);
}
