/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 08:00:19 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 08:22:20 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot_calc(t_fra *fra, t_man *man)
{
	
}

void		mandelbrot(t_fra *fra)
{
	t_man	man;
	(void)fra;//
	man.y = 0;
	while (man.y < W_HEIGHT)
	{
		man.x = 0;
		while (man.x < W_WIDTH)
		{
			mandelbrot_calc(fra, &man);
			++man.x;
		}
		++man.y;
	}
}
