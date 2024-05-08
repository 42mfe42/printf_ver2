/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:04:12 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/08 13:56:46 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h> //variadic
#include "libft/libft.h"

int ft_putnbr_hex(long long n, int if_upper);
void ft_putchar(char c);
int ft_putnbr(long long n);
ft_printf_spec(char *str, va_list arguments_list);
int	ft_print_c(char c);

#endif