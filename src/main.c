/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 20:07:06 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

int		main(int ac, char **av)
{
	t_error		ret;
	t_fra		fra;

	ft_bzero(&fra, sizeof(t_fra));
	init_functions(&fra);
	if ((ret = parse_arguments(&fra, ac, av)) != ok)
		leave(ret, &fra);
	if ((ret = init_fractol(&fra)) != ok)
		leave(ret, &fra);
	return (0);
}
