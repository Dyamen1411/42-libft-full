/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/11/19 17:20:38 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define BASE "0123456789"
#define PREFIX ""

int	printer__integer(
		int fd,
		va_list *list,
		t_format *fmt)
{
	static t_number_base	_base = (t_number_base){
	{.size = sizeof(BASE) - 1, .str = BASE},
	{.size = sizeof(PREFIX) - 1, .str = PREFIX},
		1,
	};
	long long				n;

	n = (long long) va_arg(*list, int);
	return (integer_printer_fd(fd, fmt, &_base, n));
}
