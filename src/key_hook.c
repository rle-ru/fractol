/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:30:53 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 20:45:07 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "libft.h"
#include <complex.h>

#include <stdio.h>//
int		key_hook(int key, t_fra *fra)
{
	if (key == K_ESC)
		leave(ok, fra);
	if (key == K_RIGHT || key == K_LEFT)
		fra->data.x1 += key == K_RIGHT ? 10 : -10;
	if (key == K_DOWN || key == K_UP)
		fra->data.y1 += key == K_DOWN ? 10 : -10;
	if (key == K_Q || key == K_E)
		fra->data.max_iter += key == K_Q ? 1 : -1;
	if (key == K_OSQUARE_BRA || key == K_CSQUARE_BRA)
	{
		fra->curr_color += key == K_OSQUARE_BRA ? -1 : 1;
		if (fra->curr_color >= MAX_COLORS)
			fra->curr_color = 0;
		if (fra->curr_color < 0)
			fra->curr_color = MAX_COLORS - 1;
	}
	if (key == K_A || key == K_D)
	{
		fra->curr_fractal += key == K_A ? -1 : 1;
		if (fra->curr_fractal >= MAX_FRACTALS)
			fra->curr_fractal = 0;
		if (fra->curr_fractal < 0)
			fra->curr_fractal = MAX_FRACTALS - 1;
		ft_bzero(&fra->data, sizeof(t_data));
		fra->data.zoom = 0.01;
		fra->data.max_iter = 100;
		fra->data.julia = 0.274 - I * 0.008;
	}
	return (0);
}
