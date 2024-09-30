/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:17:05 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/25 14:12:17 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	char	*res;
	int		s_len;
	int		i;

	s_len = ft_strlen(str);
	i = 0;
	while (i < s_len + 1)
	{
		if (str[i] == (char)c)
		{
			res = (char *)str + i;
			return (res);
		}
		i++;
	}
	return (0);
}
