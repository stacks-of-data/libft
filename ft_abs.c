/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:45:00 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/25 15:45:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int x)
{
	if (x < 0)
		x *= -1;
	return (x);
}
