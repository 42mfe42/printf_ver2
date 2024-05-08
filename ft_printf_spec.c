/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:33:37 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/08 14:05:48 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

ft_printf_spec(char *str, va_list arguments_list)
{
	int	count_writes;
	int i;
	int if_upper;

	i = 0;
	count_writes = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '%')
			{
			if(str[i+1] == '%')
				count_writes += ft_print_c("%"); //tu chyba bedzie blad - bo na dole daje i=i+2;
			else if(str[i+1] == 's')
				count_writes += print_str(va_arg(arguments_list, char *));
			else if(str[i+1] == 'c')
				count_writes += ft_print_c(va_arg(arguments_list, int));
			else if(str[i+1] == 'i' || str[i+1] == 'd')
				count_writes += ft_putnbr(va_arg(arguments_list, int));
			else if(str[i+1] == 'x' || str[i+1] == 'X')
			{
				if(str[i+1] == 'x')
					if_upper = 0;
				else if(str[i+1] == 'X')
					if_upper = 1;
				count_writes += ft_putnbr_hex(va_arg(arguments_list, int), if_upper);
			}
			else if(str[i+1] == 'u')
				count_writes += ft_putnbr(va_arg(arguments_list, unsigned int));
			else if(str[i+1] == 'p')
			{
				count_writes += print_str("0x");
				count_writes += ft_putnbr_hex((long long)va_arg(arguments_list, void *), 0);
			}
			i += 2;
		}
		else 
		{
			write(1, &str[i], 1);
			count_writes++;
			i++;
		}	
	}
}