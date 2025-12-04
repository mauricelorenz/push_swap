/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:24:53 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/04 14:26:06 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isspace(int c);

long	ft_atol(const char *nptr)
{
	long	i;
	int		sign;

	i = 0;
	sign = 1;
	while (isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + *nptr - '0';
		nptr++;
	}
	return (i * sign);
}

static int	isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}
