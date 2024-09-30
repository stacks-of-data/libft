/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:24:55 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/25 15:36:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *src, int c, unsigned int size)
{
	char			*src_cp;
	unsigned int	i;

	i = 0;
	src_cp = src;
	while (i < size)
	{
		src_cp[i] = c;
		i++;
	}
	return (src_cp);
}
