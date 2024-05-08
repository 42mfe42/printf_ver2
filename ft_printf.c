/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfedorys <mfedorys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:03:57 by mfedorys          #+#    #+#             */
/*   Updated: 2024/05/08 13:41:43 by mfedorys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int print_str(char* str)
{
	int j;
	j = 0;
	while(str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
	}
	return(j);
}

int ft_printf( const char *str, ...)
{
	va_list	arguments_list;
	int counts_write;
	char *pointer_to_next_arg;

	int i;
	int j;
	
	char print_c;
	int print_i;
	int if_upper;
	unsigned int print_u;
	void *print_p;

	i = 0;
	j = 0;
	if_upper = 0;
	counts_write = 0;
	va_start (arguments_list, str); //last fixed para -> str
	counts_write = ft_printf_spec( str, arguments_list);
	va_end (arguments_list);
	return (counts_write);
}

int main(void)
{
	int n, m;
	char string[] = "oooo";
	n = ft_printf("");
	printf("\nreturned %d\n", n);
	
	n = ft_printf("%s %s!", "Hello", "world");
	printf("\nreturned %d\n", n);
	n = ft_printf("%s %s %s %s!", "Hello", "world", "and", "you");
	m = ft_printf("Hello World!");
	printf("\nreturned %d\n", m);
	n = ft_printf("Hello %s", "world!");
	printf("\nreturned %d\n", n);
	n = ft_printf("Hello %s!", "world");
	printf("\nreturned %d\n", n);
	printf("\nreturned %d\n", n);
	n = ft_printf("100%%");
	printf("\nreturned %d\n", n);
	n = ft_printf("%c", 'a');
	printf("\nreturned %d\n", n);
	n = ft_printf("%d", 155);
	printf("\nreturned %d\n", n);
	n = ft_printf("%i", 62);
	printf("\nreturned %d\n", n);
	n = ft_printf("%i %d", -62, 123);
	printf("\nreturned %d\n", n);
	n = ft_printf("%u", 155);
	printf("\nreturned %d\n", n);
	n = ft_printf("%X", 0xABC);
	printf("\nreturned %d\n", n);
	n = ft_printf("%x", 0x10abcde);
	printf("\nreturned %d\n", n);
	printf("..........prinf: %p \n", string);
	n = ft_printf("..........ft_printf: %p \n", string);
	printf("\nreturned %d\n", n);
	n = ft_printf("%p", (void *)string);
	printf("\nreturned %d\n", n);



}