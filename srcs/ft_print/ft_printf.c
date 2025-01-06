/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:03:34 by amsaleh           #+#    #+#             */
/*   Updated: 2024/11/23 19:56:04 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	get_start_end(const char *str, size_t start, size_t *end)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == '%')
		{
			*end = i;
			return ;
		}
		i++;
	}
	*end = i;
}

static int	process_data(const char *str, size_t *end, va_list args)
{
	int		n;
	char	c;

	c = str[*end + 1];
	if (c == 's')
		n = printf_putstr(va_arg(args, char *));
	if (c == 'x')
		n = hex_print(va_arg(args, unsigned int), 0);
	if (c == 'X')
		n = hex_print(va_arg(args, unsigned int), 1);
	if (c == 'c')
		n = printf_putchar(va_arg(args, int));
	if (c == 'd' || c == 'i')
		n = printf_putnbr(va_arg(args, int));
	if (c == 'p')
		n = pointer_print(va_arg(args, void *));
	if (c == 'u')
		n = printf_putunbr(va_arg(args, unsigned int));
	if (c == '%')
		n = printf_putchar('%');
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	n;

	end = 0;
	len = ft_strlen(str);
	n = 0;
	va_start(args, str);
	while (end < len)
	{
		start = end;
		get_start_end(str, start, &end);
		if (end != start)
			n += putstr_range(str, start, end);
		if (str[end] == '%')
			n += process_data(str, &end, args);
		end += 2;
	}
	va_end(args);
	return (n);
}
