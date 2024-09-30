/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:14:24 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/26 14:18:44 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, void *src, unsigned int size)
{
	char			*dest_temp;
	char			*src_temp;
	unsigned int	i;

	i = 0;
	src_temp = src;
	dest_temp = dest;
	if (dest == src)
		return (dest);
	while (i < size)
	{
		*dest_temp = *src_temp;
		src_temp++;
		dest_temp++;
		i++;
	}
	return (dest);
}
