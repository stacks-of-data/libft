/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:53:18 by amsaleh           #+#    #+#             */
/*   Updated: 2024/10/12 20:37:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	add_word_lst(const char *s, int i, int j, t_list **lst)
{
	t_list	*new_lst;
	char	*temp;

	temp = ft_substr(s, j, i - j);
	if (!temp)
		return (0);
	if (!*lst)
	{
		*lst = ft_lstnew(temp);
		if (!*lst)
			return (0);
		return (1);
	}
	new_lst = ft_lstnew(temp);
	if (!new_lst)
		return (0);
	ft_lstadd_back(lst, new_lst);
	return (1);
}

t_list	*extract_words(const char *s, char c)
{
	t_list	*lst;
	int		i;
	int		j;

	i = 0;
	lst = 0;
	while (s[i] == c)
		i++;
	j = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (!add_word_lst(s, i, j, &lst))
				return (0);
			while (s[i + 1] == c)
				i++;
			j = i + 1;
		}
		i++;
	}
	if (i != j)
		if (!add_word_lst(s, i - 1, j, &lst))
			return (0);
	return (lst);
}

char	**add_words_arr(t_list *lst)
{
	char	**res;
	t_list	*node;
	int		i;

	i = 0;
	res = calloc(ft_lstsize(lst) + 1, sizeof(char *));
	if (!res)
	{
		ft_lstclear(&lst, &free);
		return (0);
	}
	node = lst;
	while (node)
	{
		res[i] = node->content;
		node = node->next;
		i++;
	}
	return (res);
}

void	free_lst(t_list **lst)
{
	t_list	*node_next;
	t_list	*node;

	node = *lst;
	while (node)
	{
		node_next = node->next;
		free(node);
		node = node_next;
	}
	*lst = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	t_list	*lst;

	if (!*s)
	{
		res = calloc(1, sizeof(char *));
		return (res);
	}
	lst = extract_words(s, c);
	if (!lst)
		return (0);
	res = add_words_arr(lst);
	if (!res)
	{
		ft_lstclear(&lst, &free);
		return (0);
	}
	free_lst(&lst);
	return (res);
}
