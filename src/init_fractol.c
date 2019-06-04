/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:14:15 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 13:42:05 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "stdlib.h"

t_error			init_fractol(t_fra *fra)
{
	if ((fra->canvas.mlx_ptr = mlx_init()) == NULL)
		return (falloc);
	if ((fra->canvas.window = mlx_new_window(
					fra->canvas.mlx_ptr, W_WIDTH, W_HEIGHT, "fract'ol")) == NULL)
		return (falloc);
	if ((fra->canvas.img.img_ptr = mlx_new_image(
					fra->canvas.mlx_ptr, W_WIDTH, W_HEIGHT)) == NULL)
		return(falloc);
	if ((fra->canvas.img.img = (int*)mlx_get_data_addr(
					fra->canvas.img.img_ptr, &fra->canvas.img.bpp,
					&fra->canvas.img.stride, &fra->canvas.img.endian)) == NULL)
		return(falloc);
	fra->data.zoom = 0.01;
	fra->data.iter = 100;
	mlx_hook(fra->canvas.window, 2, 1, key_hook, fra);
	mlx_hook(fra->canvas.window, 17, 0, leave, fra);
	mlx_loop_hook(fra->canvas.mlx_ptr, draw, fra);
	mlx_mouse_hook(fra->canvas.window, mouse_hook, fra);
	mlx_loop(fra->canvas.mlx_ptr);
	return (ok);
}
