/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 07:16:05 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/21 14:56:31 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "libft.h"
#include <pthread.h>
#include "keys.h"
#include <complex.h>
#include <stdlib.h>

static void		print_text(t_fra *fra)
{
	char	str[10];

	ft_strcpy(str, "Color:  ");
	str[8] = fra->curr_color + '0';
	if (fra->hud == false)
		return ;
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, 0, 0, 0xF0F0F0,
		fra->fractal[fra->curr_fractal].name);
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, 0, 16, 0xF0F0F0,
		str);
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 0,
		0xF0F0F0, "Enter: HUD ON/OFF");
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 16,
		0xF0F0F0, "A/D: Change fractal");
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 32,
		0xF0F0F0, "Arrows: Move");
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 48,
		0xF0F0F0, "Q/E: Inc/dec limit");
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 64,
		0xF0F0F0, "[/]: Change color set");
	mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window, W_WIDTH - 250, 80,
		0xF0F0F0, "J + Mouse: Julia's factor");
	if (fra->curr_color > 2)
		mlx_string_put(fra->canvas.mlx_ptr, fra->canvas.window,
			W_WIDTH - 250, 96, 0xF0F0F0, "T: Toggle color vibe");
}

static void		update_mouse(t_fra *fra)
{
	if (fra->keys[K_J])
		fra->data.julia = (double)(fra->mx - W_WIDTH / 2) / W_WIDTH
			+ (double)(fra->my - W_HEIGHT / 2) / W_HEIGHT * I;
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
	if (fra->data.max_iter < 3)
		fra->data.max_iter = 3;
	if (fra->data.bulbs < 1)
		fra->data.bulbs = 1;
	if (fra->data.bulbs > 5)
		fra->data.bulbs = 5;
	if (fra->curr_fractal >= MAX_FRACTALS)
		fra->curr_fractal = 0;
	if (fra->curr_fractal < 0)
		fra->curr_fractal = MAX_FRACTALS - 1;
	if (fra->data.discob)
	{
		fra->data.disco += 0.001;
		fra->data.sdisco = (sin(fra->data.disco) + 1) * 0.5;
		fra->data.sdisco = (sin(fra->data.disco) + 1) * 0.5;
		fra->data.sdisco2 = (sin(fra->data.disco * 2) + 1) * 0.5;
		fra->data.sdisco5 = (sin(fra->data.disco * 5) + 1) * 0.5;
		fra->data.sdisco10 = (sin(fra->data.disco * 10) + 1) * 0.5;
	}
}

int				draw(t_fra *fra)
{
	t_pthread	threads[MAX_THREADS];
	t_fra		cpy[MAX_THREADS];
	int			i;

	update_hooks(fra);
	update_mouse(fra);
	min_max(fra);
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
