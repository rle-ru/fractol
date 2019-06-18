/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:16:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/13 11:00:50 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <pthread.h>
#include "keys.h"
#include <complex.h>

static void		print_text(t_fra *fra)
{
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, 0, 0, 0xFFFFFF,
		fra->fractal[fra->curr_fractal].name);
}

static void		update_mouse(t_fra *fra)
{
	if (fra->keys[K_J])
		fra->data.julia = ((double)fra->mx * -0.002205)
			+ (I * (double)fra->my * 0.00081);
}

static void		update_hooks(t_fra *fra)
{
	if (fra->keys[K_RIGHT] == true)
		fra->data.x1 += 10;
	if (fra->keys[K_LEFT] == true)
		fra->data.x1 -= 10;
	if (fra->keys[K_UP] == true)
		fra->data.y1 -= 10;
	if (fra->keys[K_DOWN] == true)
		fra->data.y1 += 10;
	if (fra->keys[K_E] == true)
		fra->data.max_iter -= 1;
	if (fra->keys[K_Q] == true)
		fra->data.max_iter += 1;
}

static void		min_max(t_fra *fra)
{
	if (fra->data.max_iter < 1)
		fra->data.max_iter = 1;
	if (fra->data.bulbs < 1)
		fra->data.bulbs = 1;
	if (fra->data.bulbs > 5)
		fra->data.bulbs = 5;
	if (fra->curr_fractal >= MAX_FRACTALS)
		fra->curr_fractal = 0;
	if (fra->curr_fractal < 0)
		fra->curr_fractal = MAX_FRACTALS - 1;
}

int				draw(t_fra *fra)
{
	t_pthread	threads[MAX_THREADS];
	t_fra		cpy[MAX_THREADS];
	int			i;

	update_hooks(fra);
	update_mouse(fra);
	min_max(fra);
	mlx_clear_window(fra->canvas.mlx_ptr, fra->canvas.window);
	ft_bzero(fra->canvas.img.img, sizeof(int) * (unsigned long long)W_WIDTH
		* (unsigned long long)W_HEIGHT);
	i = 0;
	while (i < MAX_THREADS)
	{
		ft_memcpy(&cpy[i], fra, sizeof(t_fra));
		cpy[i].data.miny = i * W_HEIGHT / MAX_THREADS;
		cpy[i].data.maxy = (i + 1) * W_HEIGHT / MAX_THREADS;
		pthread_create(&threads[i], NULL,
			(fra->fractal[fra->curr_fractal].f), &cpy[i]);
		++i;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fra->canvas.mlx_ptr, fra->canvas.window,
		fra->canvas.img.img_ptr, 0, 0);
	print_text(fra);
	return (0);
}
