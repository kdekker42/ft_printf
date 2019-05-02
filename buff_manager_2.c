/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buff_manager_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 15:34:03 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/02 17:17:10 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_buf(char *buf)
{
	int i;

	i = 0;
	while (i < BUF_SIZE + 1)
	{
		buf[i] = '\0';
		i++;
	}
}

int		print_buf(char *buf)
{
	write(1, buf, BUF_SIZE);
	clear_buf(buf);
	return (BUF_SIZE);
}

int		print_buf_nf(char *buf, int j, t_flags *data)
{
	write(1, &buf[0], j);
	clear_buf(buf);
	free(data);
	return (j);
}

int		put_on_buf(char *buf, char *str, int *rtn, int len)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(buf);
	while (j < len)
	{
		if (i < BUF_SIZE)
		{
			buf[i] = str[j];
			j++;
			i++;
		}
		if (i == BUF_SIZE)
		{
			*rtn += print_buf(buf);
			i = 0;
		}
	}
	ft_strdel(&str);
	return (0);
}
