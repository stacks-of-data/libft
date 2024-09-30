/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:42:56 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 15:59:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	printf_putnbr(int n)
{
	int	i;
	int	flag;
	int	temp[11];

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
	i = extract_digits(temp, n);
	putnbr_helper(i, temp);
	return (get_digits_amount(n) + flag);
}
