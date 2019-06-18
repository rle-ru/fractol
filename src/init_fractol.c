/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:14:15 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/15 16:27:42 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "stdlib.h"
#include <complex.h>

t_error			init_fractol(t_fra *fra)
{
	if ((fra->canvas.mlx_ptr = mlx_init()) == NULL)
		return (falloc);
	if (!(fra->canvas.window = mlx_new_window(
					fra->canvas.mlx_ptr, W_WIDTH, W_HEIGHT, "fract'ol")))
		return (falloc);
	if ((fra->canvas.img.img_ptr = mlx_new_image(
					fra->canvas.mlx_ptr, W_WIDTH, W_HEIGHT)) == NULL)
		return (falloc);
	if ((fra->canvas.img.img = (int*)mlx_get_data_addr(
					fra->canvas.img.img_ptr, &fra->canvas.img.bpp,
					&fra->canvas.img.stride, &fra->canvas.img.endian)) == NULL)
		return (falloc);
	fra->data.julia = -0.74543 + I * 0.11301;
	fra->data.zoom = 0.01;
	fra->data.max_iter = BASE_ITER;
	mlx_hook(fra->canvas.window, 2, 1, key_hook, fra);
	mlx_hook(fra->canvas.window, 3, 1, key_unhook, fra);
	mlx_hook(fra->canvas.window, 4, 1, mouse_hook, fra);
	mlx_hook(fra->canvas.window, 5, 1, mouse_unhook, fra);
	mlx_hook(fra->canvas.window, 6, 1, mouse_notify, fra);
	mlx_hook(fra->canvas.window, 17, 0, leave, fra);
	mlx_loop_hook(fra->canvas.mlx_ptr, draw, fra);
	mlx_loop(fra->canvas.mlx_ptr);
	return (ok);
}
