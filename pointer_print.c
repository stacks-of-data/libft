/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:23:58 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/19 17:50:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_base_helper(unsigned long n, char *base, int len)
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

int	pointer_print(void *p)
{
	int				len;
	unsigned long	temp;
	char			base[17];
	char			*res;

	len = 0;
	temp = (unsigned long)p;
	ft_strlcpy(base, "0123456789abcdef", 17);
	if (!p)
	{
		printf_putstr("(nil)");
		return (5);
	}
	while (temp)
	{
		temp /= 16;
		len++;
	}
	printf_putstr("0x");
	res = convert_base_helper((unsigned long)p, base, len);
	printf_putstr(res);
	len = ft_strlen(res) + 2;
	free(res);
	return (len);
}
