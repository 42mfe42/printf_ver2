/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:55 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/08 13:07:00 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putdighex(int i, int if_upper)
{
    if (i < 10) {
        ft_putchar(i + '0');
    } else {
        if(if_upper)
            ft_putchar(i % 10 + 'A');
        else
            ft_putchar(i % 10 + 'a');
    }
}

int	ft_putnbr_hex(long long n, int if_upper)
{
    //printf("trying to print %X ...\n", n);
	long long	nb;
    int     char_counts;
    
    nb = n;
    char_counts = 0;
	if (nb < 0)
	{
		ft_putchar('-');
        char_counts++;
		nb = -nb;
	}
	if (nb >= 16)
	{
		char_counts += ft_putnbr_hex(nb / 16, if_upper);
        ft_putdighex(nb % 16, if_upper);
        char_counts++;
	}
	if (nb >= 0 && nb < 16)
    {
		ft_putdighex(nb % 16, if_upper);
        char_counts++;
    }
    //printf("\n sprawdzam: %i \n", char_counts);
    return(char_counts);

}