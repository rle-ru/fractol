/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/10 15:19:49 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>

static void	ship_calc(t_data *data)
{
	t_complex	z;

	z = 0;
	data->iter = 0;
	while (data->iter < data->max_iter && cabs(z) < 2)
	{
		z = (cabs(z) + I * fabs(cimag(z)) * (cabs(z)
					+ I * fabs(cimag(z)))) + data->c;
		++data->iter;
	}
}

void		*burning_ship(t_fra *fra)
{
	fra->data.y = fra->data.miny;
	while (fra->data.y < fra->data.maxy)
	{
		fra->data.x = 0;
		while (fra->data.x < W_WIDTH)
		{
			fra->data.c = ((fra->data.x1 + fra->data.x - (double)W_WIDTH / 2.)
					* fra->data.zoom) + I * ((fra->data.y1 + fra->data.y
						- (double)W_HEIGHT / 2.) * fra->data.zoom);
			ship_calc(&fra->data);
			if (fra->data.iter < fra->data.max_iter)
				put_pixel(fra->canvas.img.img, &fra->data,
					fra->colors[fra->curr_color].f(&fra->data));
			else
				put_pixel(fra->canvas.img.img, &fra->data, 0);
			++fra->data.x;
		}
		++fra->data.y;
	}
	return (NULL);
}
