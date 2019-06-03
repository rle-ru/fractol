/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 06:18:10 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 20:08:13 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "fractol.h"
#include "libft.h"

static void	print_errors(t_error err)
{
	if (err == ok)
		return ;
	else if (err == usage)
		; // Add usage
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
	print_errors(error);
	free_ptrs(fra);
	exit(0);
	return (0);
}