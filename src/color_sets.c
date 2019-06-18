/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:53:30 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/15 16:04:55 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_2(void)
{
	return (0xFFFFFF);
}

int		set_1(t_data *data)
{
	if (data->iter < 64)
		return ((data->iter * 2) << 16);
	else if (data->iter < 128)
		return (((((data->iter - 64) * 128) / 126) + 128) << 16);
	else if (data->iter < 256)
		return (((((data->iter - 128) * 62) / 127) + 193) << 16);
	else if (data->iter < 512)
		return (((((data->iter - 256) * 128) / 126) + 128) << 16);
	else if (data->iter < 1024)
		return (((((data->iter - 512) * 63) / 511) + 64) << 8 | 0xFF0000);
	else if (data->iter < 2048)
		return (((((data->iter - 1024) * 63) / 1023) + 128) << 8 | 0xFF0000);
	else if (data->iter < 4096)
		return (((((data->iter - 2048) * 63) / 2047) + 192) << 8 | 0xFF0000);
	return (0xFFFF);
	// double		a;

	// a = get_gradient(data->iter, 3, data->max_iter);
	// return (get_color(0xFFFFFF, 0x0000FF, a));
}

int		set_0(t_data *data)
{
	double	a;

	a = 255 * data->iter / data->max_iter;
	return ((unsigned char)a << 16 | (unsigned char)a << 8 | (unsigned char)a);
}
