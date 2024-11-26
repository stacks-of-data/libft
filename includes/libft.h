/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:19:58 by amsaleh           #+#    #+#             */
/*   Updated: 2024/11/08 01:18:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf.h"
# include <sys/types.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_split
{
	size_t	start;
	size_t	end;
}			t_split;

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);
size_t		ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				putstr_range(const char *str, int start, int end);
int				ft_memcmp(const void *s1, const void *s2, unsigned int size);
int				ft_strncmp(const char *s1, const char *s2, unsigned int size);
int				ft_lstsize(t_list *lst);
int				ft_abs(int x);
int				find_newline(char *str);
long			ft_atol(const char *str);
char			*ft_itoa(int n);
char			*ft_strnstr(char *big, char *little, unsigned int n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, unsigned int len);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			free_array(void **arr);
void			*ft_bzero(void *src, unsigned int size);
void			*ft_calloc(unsigned int nitems, unsigned int size);
void			*ft_memchr(const void *src, int c, unsigned int n);
void			*ft_memcpy(void *dest, void *src, unsigned int size);
void			*ft_memmove(void *dest, void *src, unsigned int n);
void			*ft_memset(void *src, int c, unsigned int size);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*get_next_line(int fd);
char			**ft_split(const char *s, char c);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
