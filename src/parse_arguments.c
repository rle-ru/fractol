/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:59:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 20:23:26 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

t_error		parse_arguments(t_fra *fra, int ac, char **av)
{
	int		i;

	if (ac == 1)
		return (usage);
	i = MAX_FRACTALS;
	while (i--)
		if (!ft_strcmp(fra->fractal[i].name, av[1]))
		{
			fra->curr_fractal = i;
			return (ok);
		}
	return (usage);
}
