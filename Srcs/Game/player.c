/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:52:46 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/10 20:23:36 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_tools *data)
{
	if (!data->map)
		return (error("Error: Map is NULL before initializing player!"), 0);
	return (find_player(data));
}

void	rotate_player(t_tools *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROT_SPEED * data->player.rotate;
	if (!data->player.rotate)
		return ;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed)
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y
		* cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y
		* cos(rot_speed);
}

void	update_player(t_tools *data)
{
	double	move_speed;
	double	next_x;
	double	next_y;

	move_speed = SPEED;
	next_x = data->player.pos_x;
	next_y = data->player.pos_y;
	if (data->player.move_y)
	{
		next_x += data->player.move_y * data->player.dir_x * move_speed;
		next_y += data->player.move_y * data->player.dir_y * move_speed;
	}
	if (data->player.move_x)
	{
		next_x += data->player.move_x * data->player.plane_x * move_speed;
		next_y += data->player.move_x * data->player.plane_y * move_speed;
	}
	if (data->map[(int)next_y][(int)next_x] != '1')
	{
		data->player.pos_x = next_x;
		data->player.pos_y = next_y;
	}
	if (data->player.rotate)
		rotate_player(data);
}
