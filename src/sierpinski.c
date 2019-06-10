/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:22:57 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/10 11:00:29 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	sier_calc(t_data *data, int x, int y)
{
	(void)data;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void		*sierpinski(t_fra *fra)
{
	fra->data.y = fra->data.miny;
	fra->data.max_iter = 1;
	while (fra->data.y < fra->data.maxy)
	{
		fra->data.x = 0;
		while (fra->data.x < W_WIDTH)
		{
			if ((fra->data.iter = sier_calc(&fra->data, (fra->data.x1 + fra->data.x) * fra->data.zoom, (fra->data.y + fra->data.y1) * fra->data.zoom)))
				puopent_pixel(fra->canvas.img.img, &fra->data, fra->colors[fra->curr_color].f(&fra->data));
			else
				put_pixel(fra->canvas.img.img, &fra->data, 0);
			++fra->data.x;
		}
		++fra->data.y;
	}
	return (NULL);
}
