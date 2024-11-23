/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:11:15 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/26 12:29:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 0x40 && c < 0x5B) || (c > 0x60 && c < 0x7B))
		return (1);
	else
		return (0);
}