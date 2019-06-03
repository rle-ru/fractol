/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 19:35:13 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <complex.h>//
#include "libft.h"////
static int	mandelbrot_calc(t_fra *fra, t_man *man)
{
	t_complex	z;
	int			i;

	(void)fra;
	z = 0;
	i = 0;
	while (i < man->iter && cabs(z) <= 2)
	{
		z = z * z + man->c;
		++i;
	}
	return (i);
}

void		put_pixel(t_fra *fra, t_man *man)
{
	fra->canvas.img.img[man->y * W_WIDTH + man->x] = 0xFF;
}


void		mandelbrot(t_fra *fra)
{
	t_man	man;
	int		i;

	man.y = 0;
	man.iter = 100;
	while (man.y < W_HEIGHT)
	{
		man.x = 0;
		while (man.x < W_WIDTH)
		{
			man.c = ((man.x - (double)W_WIDTH / 2.) * 0.01) + I * ((man.y - (double)W_HEIGHT / 2.) * 0.01);
			i = mandelbrot_calc(fra, &man);
			if (i < man.iter)
				put_pixel(fra, &man);
			++man.x;
		}
		++man.y;
	}
}
