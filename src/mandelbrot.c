/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 11:09:49 by rle-ru           ###   ########.fr       */
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

void		mandelbrot(t_fra *fra)
{
	int		i;
	t_data	data;

	data.y = 0;
	data.iter = 100;
	while (data.y < W_HEIGHT)
	{
		data.x = 0;
		while (data.x < W_WIDTH)
		{
			data.c = ((data.x - (double)W_WIDTH / 2.) * 0.01) + I * ((data.y - (double)W_HEIGHT / 2.) * 0.01);
			i = mandelbrot_calc(&data);
			if (i < data.iter)
				put_pixel(fra->canvas.img.img, &data, 0xFF);
			++data.x;
		}
		++data.y;
	}
}
