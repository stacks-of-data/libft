/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:41:26 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/27 10:41:30 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *big, char *little, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!little[0])
		return (big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (i + j >= n)
				return (0);
			j++;
			if (!little[j])
				return (big + i);
		}
		i++;
	}
	return (0);
}
