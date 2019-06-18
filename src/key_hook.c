/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:30:53 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/15 16:27:57 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include "libft.h"
#include <complex.h>

int		key_unhook(int key, t_fra *fra)
{
	fra->keys[key] = false;
	return (0);
}

int		key_hook(int key, t_fra *fra)
{
	fra->keys[key] = true;
	if (key == K_ESC)
		leave(ok, fra);
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
		ft_bzero(&fra->data, sizeof(t_data));
		fra->data.zoom = 0.01;
		fra->data.max_iter = BASE_ITER;
		fra->data.julia = -0.74543 + I * 0.11301;
	}
	if (key == K_PLUS || key == K_MINUS)
		fra->data.bulbs += key == K_PLUS ? 1 : -1;
	return (0);
}
