/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 13:42:00 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

static int	mandelbrot_calc(t_data *data)
{
	t_complex	z;
	int			i;

	z = 0;
	i = 0;
	while (i < data->iter && cabs(z) <= 2)
	{
		z = z * z + data->c;
		++i;
	}
	return (i);
}

void		*mandelbrot(t_fra *fra)
{
	int		i;

	fra->data.y = fra->data.miny;
	while (fra->data.y < fra->data.maxy)
	{
		fra->data.x = 0;
		while (fra->data.x < W_WIDTH)
		{
			fra->data.c = ((fra->data.x1 + fra->data.x- (double)W_WIDTH / 2.) * fra->data.zoom) + I * ((fra->data.y1 + fra->data.y - (double)W_HEIGHT / 2.) * fra->data.zoom);
			i = mandelbrot_calc(&fra->data);
			if (i < fra->data.iter)
				put_pixel(fra->canvas.img.img, &fra->data, 0xFF);
			++fra->data.x;
		}
		++fra->data.y;
	}
	return (NULL);
}
