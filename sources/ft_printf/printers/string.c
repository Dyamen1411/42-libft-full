/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:15:03 by amassias          #+#    #+#             */
/*   Updated: 2023/11/11 19:33:53 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * @param str 
 * @param len 
 * @author amassias (amassias@42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation
 */
static void	_putnstr_fd(
				int fd,
				const char *str,
				size_t len);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	string_printer_fd(
		int fd,
		t_format *fmt,
		char *str)
{
	size_t	slen;
	size_t	len;

	slen = ft_strlen(str);
	if (fmt__precision(fmt))
		slen = min(fmt->precision, slen);
	fmt->width = max(0, fmt->width - slen);
	len = slen + fmt->width;
	if (fmt__left_justify(fmt))
		_putnstr_fd(fd, str, slen);
	putnchar_fd(fd, ' ', fmt->width);
	if (!fmt__left_justify(fmt))
		_putnstr_fd(fd, str, slen);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	_putnstr_fd(
				int fd,
				const char *str,
				size_t len)
{
	while (len--)
		ft_putchar_fd(*str++, fd);
}
