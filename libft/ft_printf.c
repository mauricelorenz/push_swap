/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlorenz <mlorenz@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:45:55 by mlorenz           #+#    #+#             */
/*   Updated: 2025/12/04 15:50:46 by mlorenz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_format(const char c, va_list *args);
static int	ft_putstr_count(char *s, char c);
static int	ft_putptr_count(unsigned long ptr, int first_call);
static int	ft_putnbr_base_count(long n, int base, char c);

int	ft_printf(const char *str, ...)
{
	int		printed_chars;
	int		chars_total;
	va_list	args;

	printed_chars = 0;
	chars_total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			printed_chars = handle_format(*(str + 1), &args);
			if (printed_chars == -1)
				return (va_end(args), chars_total);
			str = str + 2;
		}
		else
		{
			printed_chars = ft_putstr_count((char *)str, 'c');
			str++;
		}
		chars_total += printed_chars;
	}
	return (va_end(args), chars_total);
}

static int	handle_format(const char c, va_list *args)
{
	char	x;

	if (c == 'c')
	{
		x = va_arg(*args, int);
		return (ft_putstr_count(&x, c));
	}
	if (c == 's')
		return (ft_putstr_count(va_arg(*args, char *), c));
	else if (c == 'p')
		return (ft_putptr_count(va_arg(*args, unsigned long), 1));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (ft_putnbr_base_count(va_arg(*args, int), 10, c));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_base_count(va_arg(*args, int), 16, c));
	else if (c == '%')
		return (ft_putstr_count("%", c));
	return (ft_putstr_count("%", 'c') + ft_putstr_count((char *)&c, 'c'));
}

static int	ft_putstr_count(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6), 6);
	if (c == 'c')
		return (write(1, s, 1));
	while (*s)
	{
		write(1, s, 1);
		s++;
		i++;
	}
	return (i);
}

static int	ft_putptr_count(unsigned long ptr, int first_call)
{
	int				i;
	unsigned long	n;

	i = 0;
	n = (unsigned long)ptr;
	if (n == 0)
		return (write(1, "(nil)", 5), 5);
	if (first_call)
	{
		write(1, "0x", 2);
		i += 2;
	}
	if (n >= 16)
		i += ft_putptr_count(n / 16, 0);
	if ((n % 16) >= 10)
		n = n % 16 - 10 + 'a';
	else
		n = n % 16 + '0';
	return (i + write(1, &n, 1));
}

static int	ft_putnbr_base_count(long n, int base, char c)
{
	int	i;

	i = 0;
	if (c == 'd' || c == 'i')
		n = (int)n;
	if (c == 'u' || c == 'x' || c == 'X')
		n = (unsigned int)n;
	if ((n == -2147483648) && (c == 'd' || c == 'i'))
		return (write(1, "-2147483648", 11));
	if ((n < 0) && (c == 'd' || c == 'i'))
	{
		i = i + write(1, "-", 1);
		n = (-n);
	}
	if (n >= base)
		i += ft_putnbr_base_count(n / base, base, c);
	if (((n % base) >= 10) && c == 'X')
		n = n % base - 10 + 'A';
	else if ((n % base) >= 10)
		n = n % base - 10 + 'a';
	else
		n = n % base + '0';
	return (i + write(1, &n, 1));
}
