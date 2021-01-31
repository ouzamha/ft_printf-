/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:33:13 by ouzamhar          #+#    #+#             */
/*   Updated: 2019/06/28 21:35:09 by ouzamhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	o_string(va_list ap, t_fo str, int *re)
{
	ou_string(ap, str, re, 8);
}

void	u_string(va_list ap, t_fo str, int *re)
{
	ou_string(ap, str, re, 10);
}
