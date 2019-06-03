/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:30:53 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 17:20:38 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		key_hook(int key, t_fra *fra)
{
	if (key == K_ESC)
		leave(ok, fra);
	if (key == K_RIGHT || key == K_LEFT) // Change the key
	{
		fra->curr_fractal += key == K_RIGHT ? 1 : -1;
		if (fra->curr_fractal >= MAX_FRACTALS)
			fra->curr_fractal = 0;
		if (fra->curr_fractal < 0)
			fra->curr_fractal = MAX_FRACTALS - 1;
	}
	return (0);
}
