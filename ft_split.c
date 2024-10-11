/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:53:18 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/24 21:08:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_str_start_end(const char *s, char c, int *start, int *end)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	*start = i;
	while (s[i])
		i++;
	while (s[i - 1] == c)
		i--;
	*end = i;
}

static char	*split_process(const char *s, int *start, int *track, char c)
{
	char	*res;

	if (!s[*start])
		(*start)--;
	if (*start - *track == 0)
		res = ft_substr(s, *track, 1);
	else
		res = ft_substr(s, *track, *start - *track);
	if (!s[*start + 1])
		(*start)++;
	while (s[*start] == c)
		(*start)++;
	*track = *start;
	return (res);
}

static void	search_delimiters_and_split(const char *s, char **res, char c)
{
	int	start;
	int	end;
	int	track;
	int	flag;

	get_str_start_end(s, c, &start, &end);
	track = start;
	flag = 0;
	while (start < end + 1)
	{
		if ((s[start] == c || !s[start]) && !flag)
		{
			if (!s[start])
				flag = 1;
			*res = split_process(s, &start, &track, c);
			if (!*res)
				free_array((void **)res);
			if (!*res)
				return ;
			res++;
		}
		else
			start++;
	}
	*res = 0;
}

static int	get_delimiters_count(const char *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		c_count;

	c_count = get_delimiters_count(s, c);
	if (!c_count)
	{
		if (!ft_strlen(s))
		{
			res = malloc(sizeof(char *));
			if (!res)
				return (0);
			res[0] = 0;
			return (res);
		}
		res = malloc(2 * sizeof(char *));
		res[0] = ft_strdup(s);
		res[1] = 0;
		return (res);
	}
	res = malloc((c_count + 2) * sizeof(char *));
	if (!res)
		return (0);
	search_delimiters_and_split(s, res, c);
	return (res);
}

