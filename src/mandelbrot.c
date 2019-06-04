/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 11:30:08 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <complex.h>//
#include "libft.h"////
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
	fra->data.iter = 100;
	while (fra->data.y < fra->data.maxy)
	{
		fra->data.x = 0;
		while (fra->data.x < W_WIDTH)
		{
			fra->data.c = ((fra->data.x - (double)W_WIDTH / 2.) * 0.01) + I * ((fra->data.y - (double)W_HEIGHT / 2.) * 0.01);
			i = mandelbrot_calc(&fra->data);
			if (i < fra->data.iter)
				put_pixel(fra->canvas.img.img, &fra->data, 0xFF);
			++fra->data.x;
		}
		++fra->data.y;
	}
	return (NULL);
}
