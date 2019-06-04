/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:30:53 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 13:39:11 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		key_hook(int key, t_fra *fra)
{
	if (key == K_ESC)
		leave(ok, fra);
	if (key == K_RIGHT || key == K_LEFT)
		fra->data.x1 += key == K_RIGHT ? 10 : -10;
	if (key == K_DOWN || key == K_UP)
		fra->data.y1 += key == K_DOWN ? 10 : -10;
	if (key == K_Q || key == K_E)
		fra->data.iter += key == K_Q ? 50 : -50;
	// if (key == K_RIGHT || key == K_LEFT) // Change the key
	// {
	// 	fra->curr_fractal += key == K_RIGHT ? 1 : -1;
	// 	if (fra->curr_fractal >= MAX_FRACTALS)
	// 		fra->curr_fractal = 0;
	// 	if (fra->curr_fractal < 0)
	// 		fra->curr_fractal = MAX_FRACTALS - 1;
	// }
	return (0);
}
