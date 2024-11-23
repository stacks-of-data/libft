/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:42:56 by amsaleh           #+#    #+#             */
/*   Updated: 2024/11/23 20:22:30 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	get_digits_amount(int n)
{
	int	num;
	int	res;

	num = n;
	res = 0;
	if (num == -2147483648)
		return (10);
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

static int	extract_digits(int *temp, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		temp[i] = n % 10;
		n /= 10;
	}
	return (i);
}

static void	putnbr_helper(int i, int *temp)
{
	while (i > 0)
	{
		printf_putchar(temp[i] + 0x30);
		i--;
	}
}

static int	putnbr_finalizer(int n, int flag, int *temp)
{
	int	i;
	int	res;

	i = extract_digits(temp, n);
	putnbr_helper(i, temp);
	res = get_digits_amount(n) + flag;
	return (res);
}

int	printf_putnbr(int n)
{
	int	flag;
	int	temp[11];
	int	res;

	flag = 0;
	if (!n)
	{
		printf_putchar('0');
		return (1);
	}
	if (n == -2147483648)
	{
		printf_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		printf_putchar('-');
		n *= -1;
		flag = 1;
	}
	res = putnbr_finalizer(n, flag, temp);
	return (res);
}
