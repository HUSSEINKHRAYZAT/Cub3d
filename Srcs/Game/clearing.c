/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:47:01 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 17:00:49 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	clear_image(t_tools *data)
{
	memset(data->addr, 0, WIN_WIDTH * WIN_HEIGHT * (data->bpp / 8));
}

int	close_window(t_tools *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
	return (0);
}
