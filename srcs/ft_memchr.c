/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:23 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/29 19:02:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *src, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)src;
	while (i < n)
	{
		if (*res == (unsigned char)c)
			return (res);
		res++;
		i++;
	}
	return (0);
}
