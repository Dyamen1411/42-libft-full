/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:36:08 by amassias          #+#    #+#             */
/*   Updated: 2023/11/18 16:25:21 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hex.c
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* ************************************************************************** */
/*                                                                            */
/* Defines                                                                    */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief All the uppercase digits of hexadecimal followed by the uppercase
 * hexadecimal prefix.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
#define U_CHARSET "0123456789ABCDEF0X"

/**
 * @brief All the lowercase digits of hexadecimal followed by the lowercase
 * hexadecimal prefix.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
#define L_CHARSET "0123456789abcdef0x"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Computes the length in character of an hexadecimal number.
 * @param n A number.
 * @return The length of `n` in hexadecimal.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static int	_len(
				size_t n);

/**
 * @brief Puts an hexadecimal number `n` onto the file descriptor `fd` using the
 * charset `charset`.
 * @param charset The charset to use to print the number.
 * @param n The number to print.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
static void	_print_hex_fd(
				int fd,
				const char *charset,
				size_t n);

/**
 * @brief Using the specified format `fmt`, puts a formatted hexadecimal number
 * `n` to the file descriptor `fd`.
 * @param fd The file descriptor on which to put the formatted hexadecimal
 * number `n`.
 * @param fmt The format to use.
 * @param n The hexadecimal number to format.
 * @param u Flag to indicate if the hexadecimal letters should be uppercase or
 * lowercase.
 * @return The number of characters put onto the file decriptor `fd`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @see ft_fprintf
 */
static void	_print_fd(
				int fd,
				t_format *fmt,
				size_t n,
				int u);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	hex_printer_fd(
		int fd,
		t_format *fmt,
		size_t n)
{
	int	number_size;
	int	prefix;

	if (fmt__use_precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = _len(n);
	fmt->precision -= number_size;
	if (n == 0)
		fmt->flags &= ~FMT_FLAG__PREFIX;
	prefix = 2 * fmt__prefix(fmt);
	if (prefix)
		fmt->width -= 2;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__use_precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = ft_max(0, fmt->precision);
	fmt->width = ft_max(0, fmt->width - number_size - fmt->precision);
	_print_fd(fd, fmt, n, fmt->specifier == 'X');
	return (prefix + number_size + fmt->width + fmt->precision);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static int	_len(
				size_t n)
{
	int	len;

	len = 1;
	while (n > 0xf)
	{
		++len;
		n >>= 4;
	}
	return (len);
}

static void	_print_hex_fd(
				int fd,
				const char *charset,
				size_t n)
{
	if (n > 0xf)
		_print_hex_fd(fd, charset, n >> 4);
	ft_putchar_fd(charset[n & 0xf], fd);
}

static void	_print_fd(
				int fd,
				t_format *fmt,
				size_t n,
				int u)
{
	char	*charset;

	charset = L_CHARSET;
	if (u)
		charset = U_CHARSET;
	if (!fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
	if (fmt__prefix(fmt)
		&& (!fmt__use_precision(fmt) || fmt->precision >= 0 || n))
		ft_putstr_fd(&charset[sizeof(L_CHARSET) - 3], 1);
	putnchar_fd(fd, '0', fmt->precision);
	if (!fmt__use_precision(fmt) || fmt->precision != 0 || n != 0)
		_print_hex_fd(fd, charset, n);
	if (fmt__left_justify(fmt))
		putnchar_fd(fd, ' ', fmt->width);
}
