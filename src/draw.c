/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:16:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 11:09:19 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <pthread.h>

int			draw(t_fra *fra)
{
	// t_pthread	threads[MAX_THREADS];

	ft_bzero(fra->canvas.img.img, sizeof(int) * W_WIDTH * W_HEIGHT);
	fra->fractal[fra->curr_fractal].f(fra);
	mlx_put_image_to_window(fra->canvas.mlx_ptr, fra->canvas.window,
		fra->canvas.img.img_ptr, 0, 0);
	return (0);
}
