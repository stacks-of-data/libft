/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:45:21 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/19 17:49:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

void	print_char_repeat(char c, int count)
{
	char	*res;

	res = malloc(count);
	if (!res)
		return ;
	ft_memset(res, c, count);
	write(1, res, count);
}

int	putstr_range(const char *str, int start, int end)
{
	int		len;
	char	*sub_str;

	len = end - start;
	if (start == end)
	{
		printf_putchar(str[start]);
		return (1);
	}
	sub_str = ft_substr(str, start, len);
	printf_putstr((char *)sub_str);
	free(sub_str);
	return (len);
}
