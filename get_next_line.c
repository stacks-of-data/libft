/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:41:16 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/02 10:11:13 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	init_data(char **res, char *buf)
{
	int	i;

	i = 0;
	if (!*buf)
	{
		while (i < BUFFER_SIZE)
		{
			buf[i] = 0;
			i++;
		}
	}
	*res = malloc(BUFFER_SIZE + 1);
	if (!*res)
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		(*res)[i] = 0;
		i++;
	}
	return (1);
}

static char	*handle_bad_read(int b_read, char *buf, char *res)
{
	char	*new_res;

	if (*buf && b_read != -1)
	{
		new_res = ft_substr(res, 0, ft_strlen(res));
		free(res);
		ft_memmove(buf, buf + ft_strlen(buf), ft_strlen(buf));
		return (new_res);
	}
	buf[0] = 0;
	free(res);
	return (0);
}

static char	*clean_return_res(int newline_i, char *buf, char *res)
{
	char	*new_res;
	char	*new_buf;

	new_buf = ft_substr(buf, 0, newline_i + 1);
	ft_memmove(buf, buf + newline_i + 1, ft_strlen(buf + newline_i));
	new_res = ft_strjoin(res, new_buf);
	free(res);
	free(new_buf);
	return (new_res);
}

static char	*get_next_line_process(int fd, char *buf, char *res)
{
	int		b_read;
	int		newline_i;
	char	*new_res;

	newline_i = -1;
	b_read = BUFFER_SIZE;
	while (1)
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (!b_read || b_read == -1)
			return (handle_bad_read(b_read, buf, res));
		buf[b_read] = 0;
		newline_i = find_newline(buf);
		if (newline_i != -1)
			break ;
		new_res = ft_strjoin(res, buf);
		free(res);
		res = new_res;
	}
	return (clean_return_res(newline_i, buf, res));
}

char	*get_next_line(int fd)
{
	int			newline_i;
	static char	buf[BUFFER_SIZE];
	char		*res;
	char		*new_res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!init_data(&res, buf))
		return (0);
	if (*buf)
	{
		newline_i = find_newline(buf);
		if (newline_i != -1)
		{
			new_res = ft_substr(buf, 0, newline_i + 1);
			ft_memmove(buf, buf + newline_i + 1, ft_strlen(buf + newline_i));
			free(res);
			return (new_res);
		}
		else
			ft_memmove(res, buf, ft_strlen(buf));
	}
	res = get_next_line_process(fd, buf, res);
	return (res);
}
