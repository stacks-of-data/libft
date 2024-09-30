/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:07:35 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/01 14:24:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first_lst;
	t_list	*node;

	new_lst = ft_lstnew(0);
	if (!lst || !f || !del || !new_lst)
		return (0);
	first_lst = new_lst;
	node = lst;
	while (node)
	{
		if (node->content)
			new_lst->content = f(node->content);
		if (node->next)
		{
			new_lst->next = ft_lstnew(0);
			if (!new_lst->next)
				free(new_lst->next);
			if (!new_lst->next)
				return (0);
		}
		node = node->next;
		new_lst = new_lst->next;
	}
	return (first_lst);
}
