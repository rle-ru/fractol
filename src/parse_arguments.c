/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:59:56 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/04 09:08:26 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_error		parse_arguments(t_fra *fra, int ac, char **av)
{
	(void)fra;//
	(void)av;//
	if (ac == 1)
		return (usage);
	return (ok);
}
