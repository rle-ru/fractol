/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 20:11:53 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

static void		julia_calc(t_data *data)
{
	t_complex	z;

	// z = data->julia;
	z = data->c;
	data->iter = 0;
	while (data->iter < data->max_iter && creal(z) * creal(z) + cimag(z) * cimag(z) < 4)
	{
		// z = (1 + (data->julia - 1) * cpow(z, data->julia)) / (data->julia * cpow(z, data->julia - 1));
		z = z * z + data->julia;
		// z = csqrt(z - data->c);
		++data->iter;
	}
}

void			*julia(t_fra *fra)
{
	fra->data.y = fra->data.miny;
	while (fra->data.y < fra->data.maxy)
	{
		fra->data.x = 0;
		while (fra->data.x < W_WIDTH)
		{
			fra->data.c = ((fra->data.x1 + fra->data.x - (double)W_WIDTH / 2.) * fra->data.zoom) + I * ((fra->data.y1 + fra->data.y - (double)W_HEIGHT / 2.) * fra->data.zoom);
			julia_calc(&fra->data);
			if (fra->data.iter < fra->data.max_iter)
				put_pixel(fra->canvas.img.img, &fra->data, fra->colors[fra->curr_color].f(&fra->data));
			else
				put_pixel(fra->canvas.img.img, &fra->data, 0);
			++fra->data.x;
		}
		++fra->data.y;
	}
	return (NULL);
}
