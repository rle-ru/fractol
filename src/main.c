/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 08:11:48 by rle-ru            #+#    #+#             */
/*   Updated: 2019/06/03 06:19:04 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	//
#include "fractol.h"//

int		main(int ac, char **av)
{
	t_error		ret;
	t_fra		fra;

	if ((ret = init_fractol(&fra)) != ok)
		leave(ret);
	return (0);
}
