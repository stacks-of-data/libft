/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:25:12 by amsaleh           #+#    #+#             */
/*   Updated: 2024/08/31 20:30:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*node;

	i = 1;
	if (!lst)
		return (0);
	if (!lst->next)
		return (1);
	node = lst->next;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}
