/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:14:40 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 10:19:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*res;
	unsigned int	i;
	unsigned int	l_len;

	i = -1;
	l_len = len;
	if (start >= ft_strlen(s))
	{
		res = malloc(1 * sizeof(char));
		if (!res)
			return (0);
		res[0] = 0;
		return (res);
	}
	if (l_len + start >= ft_strlen(s))
		l_len = ft_strlen(s);
	res = malloc((l_len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (++i < l_len)
		res[i] = s[start + i];
	res[i] = 0;
	return (res);
}
