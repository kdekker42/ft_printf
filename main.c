/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:58:03 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/03 20:31:08 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int ft_value;
	int printf_value;
	// int f = 52522;
	// int p = 52522;



	ft_value = ft_printf("titi % +---12.5% et%%%0004% et %+1%");
	printf("\t%d\n", ft_value);
	printf_value = printf("titi % +---12.5% et%%%0004% et %+1%");
	printf("\t%d\n", printf_value);

//	printf("data->width: %d\tdata->flags: %c\tdata->precision: %d\tdata->length: %i\tdata->specifier: %c\tdata->result: %s\n", \
	data->width, data->flags, data->precision, data->length, data->specifier, data->result);
//	while(1);
}