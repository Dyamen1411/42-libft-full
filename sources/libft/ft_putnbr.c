/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 02:23:50 by amassias          #+#    #+#             */
/*   Updated: 2023/11/26 02:25:26 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr.c
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-26
 * @copyright Copyright (c) 2023
 * @note This function is not part of the original libft.
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/* Helper prototypes                                                          */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Outputs the unsigned integer n to the standard output.
 * @param n The integer to output.
 * @author Antoine Massias (amassias@student.42lehavre.fr)
 * @date 2023-11-26
 */
static void	_ft_putnbr(
				unsigned int n);

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(
			signed int _n)
{
	long	n;

	n = _n;
	if (n < 0)
	{
		ft_putchar('-', STDOUT_FILENO);
		n = -n;
	}
	_ft_putnbr(n);
}

/* ************************************************************************** */
/*                                                                            */
/* Helper implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

static void	_ft_putnbr(
				unsigned int n)
{
	if (n > 9)
		_ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}
