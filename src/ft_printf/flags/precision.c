/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:33:59 by amassias          #+#    #+#             */
/*   Updated: 2024/05/11 18:00:33 by Antoine Mas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file precision.c
 * @author Antoine Massias (massias.antoine.pro@gmail.com)
 * @date 2023-11-06
 * @copyright Copyright (c) 2023
 */

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/* Header implementations                                                     */
/*                                                                            */
/* ************************************************************************** */

int	fmt__use_precision(
		t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__USE_PRECISION) != 0);
}