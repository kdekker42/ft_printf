/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buff_manager.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/21 16:10:15 by kpereira       #+#    #+#                */
/*   Updated: 2019/05/02 17:47:29 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reset_j(int *j, int *rtn, char *buf)
{
	*rtn += print_buf(buf);
	*j = 0;
}

static void	assign_char_to_buf(char *buf, char *format, int *j, int i)
{
	buf[*j] = format[i];
	*j = *j + 1;
}

static void	assign_int_zero(int *i, char *str, t_flags **data)
{
	*i = 0;
	i++;
	*i = 0;
	i++;
	*i = 0;
	clear_buf(str);
	*data = 0;
}

static void	free_data(t_flags **data)
{
	if (data)
	{
		free(*data);
		*data = NULL;
	}
}

int			buff_management(char *format, va_list list)
{
	t_flags	*data;
	char	buf[BUF_SIZE + 1];
	int		i[3];

	assign_int_zero(&i[0], buf, &data);
	while (format[i[0]] != '\0')
	{
		if (i[1] == BUF_SIZE)
			reset_j(&i[1], &i[2], buf);
		if (format[i[0]] == '%' && format[i[0] + 1])
		{
			data = get_string_to_print(list, (const char *)&format[i[0]]);
			if (!data)
				break ;
			i[0]++;
			i[1] = (i[1] + (LEN)) % BUF_SIZE;
			i[2] += put_on_buf(buf, data->result, &i[2], (LEN));
			i[0] += ft_search_until_specifier(&format[i[0]], data);
			free_data(&data);
		}
		else if (format[i[0]] != '%')
			assign_char_to_buf(buf, format, &i[1], i[0]);
		i[0]++;
	}
	return (i[2] += print_buf_nf(buf, i[1], data));
}
