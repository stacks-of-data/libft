/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putunbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:42:56 by amsaleh           #+#    #+#             */
/*   Updated: 2024/11/23 20:09:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	get_digits_amount_unsigned(unsigned int n)
{
	unsigned int	num;
	unsigned int	res;

	num = n;
	res = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		res++;
	}
	return (res);
}

int	extract_digits_unsigned(int *temp, unsigned int n)
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

int	printf_putunbr(unsigned int n)
{
	int	i;
	int	temp[11];
	int res;

	if (!n)
	{
		printf_putchar('0');
		return (1);
	}
	i = extract_digits_unsigned(temp, n);
	while (i > 0)
	{
		printf_putchar(temp[i] + 0x30);
		i--;
	}
	res = get_digits_amount_unsigned(n);
	return (res);
}
