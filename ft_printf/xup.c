/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 21:37:56 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 21:49:53 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	x_string(va_list ap, t_fo str, int *re)
{
	hex(ap, str, re, "0123456789abcdef");
}

void	upx_string(va_list ap, t_fo str, int *re)
{
	heupx(ap, str, re, "0123456789ABCDEF");
}
