/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:18:10 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 20:44:10 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

static void	ft_usage(t_fra *fra)
{
	int	i;

	i = 0;
	ft_putstr("Usage : ./fractol");
	while (i < MAX_FRACTALS)
	{
		ft_putchar(' ');
		ft_putstr(fra->fractal[i].name);
		++i;
	}
	ft_putchar('\n');
}

static void	print_errors(t_error err, t_fra *fra)
{
	if (err == ok)
		return ;
	else if (err == usage)
		ft_usage(fra);
	else if (err == falloc)
		ft_putstr_fd("A malloc returned NULL\n", STDERR_FILENO);
}

static void	free_ptrs(t_fra *fra)
{
	if (fra->canvas.img.img != NULL)
		mlx_destroy_image(fra->canvas.mlx_ptr, fra->canvas.img.img_ptr);
	if (fra->canvas.window)
		mlx_destroy_window(fra->canvas.mlx_ptr, fra->canvas.window);
}

int			leave(t_error error, t_fra *fra)
{
	print_errors(error, fra);
	free_ptrs(fra);
	exit(0);
	return (0);
}