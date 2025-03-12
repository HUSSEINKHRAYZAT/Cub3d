/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:47:10 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 17:14:43 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_tools *data)
{
	if (key == 65307)
		close_window(data);
	else if (key == 119)
		data->player.move_y = 1;
	else if (key == 115)
		data->player.move_y = -1;
	else if (key == 97)
		data->player.move_x = -1;
	else if (key == 100)
		data->player.move_x = 1;
	else if (key == 65361)
		data->player.rotate = -1;
	else if (key == 65363)
		data->player.rotate = 1;
	return (0);
}

int	key_release(int key, t_tools *data)
{
	if (key == 119 || key == 115)
		data->player.move_y = 0;
	else if (key == 97 || key == 100)
		data->player.move_x = 0;
	else if (key == 65361 || key == 65363)
		data->player.rotate = 0;
	return (0);
}
