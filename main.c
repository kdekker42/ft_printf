/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:58:03 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/02 20:47:16 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int ft_value;
	int printf_value;
	int f = 52522;
	int p = 52522;


//	printf("data->width: %d\tdata->flags: %c\tdata->precision: %d\tdata->length: %i\tdata->specifier: %c\tdata->result: %s\n", \
	data->width, data->flags, data->precision, data->length, data->specifier, data->result);

	ft_value = ft_printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\tvalue: %d\n\n", ft_value);
	printf_value = printf("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
	printf("\tvalue: %d\n\n", printf_value);
//	while(1);
}
