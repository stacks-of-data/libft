/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:07:27 by amsaleh           #+#    #+#             */
/*   Updated: 2024/09/04 16:38:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				pointer_print(void *p);
int				hex_print(unsigned int n, int flag);
int				printf_putchar(char c);
int				printf_putstr(char *s);
int				printf_putnbr(int n);
int				printf_putunbr(unsigned int n);
void			print_char_repeat(char c, int count);

#endif
