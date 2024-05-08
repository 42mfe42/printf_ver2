/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:43 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/08 13:06:46 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_putnbr(long long n)
{
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
	if (nb >= 10)
	{
		char_counts += ft_putnbr(nb / 10);
		ft_putchar(((nb % 10) + '0'));
        char_counts++;
	}
	if (nb >= 0 && nb <= 9)
    {
		ft_putchar((nb + '0'));
        char_counts++;
    }
    //printf("\n sprawdzam: %i \n", char_counts);
    return(char_counts);

}