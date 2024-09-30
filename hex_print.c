/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:12:12 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/19 17:50:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_base_helper(unsigned int n, char *base, int len)
{
	char	*res;

	res = malloc(len + 1);
	if (!res)
		return (0);
	res[len] = 0;
	len--;
	while (n)
	{
		res[len] = base[n % 16];
		n /= 16;
		len--;
	}
	return (res);
}

int	hex_print(unsigned int n, int flag)
{
	int				len;
	unsigned int	temp;
	char			base[17];
	char			*res;

	len = 0;
	temp = n;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (flag)
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	if (!n)
	{
		printf_putchar('0');
		return (1);
	}
	while (temp)
	{
		temp /= 16;
		len++;
	}
	res = convert_base_helper(n, base, len);
	printf_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
