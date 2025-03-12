/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:18:08 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 16:26:28 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
	}
	if (dir == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
	}
	if (dir == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
	}
	if (dir == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
	}
}

void	set_player_plane(t_player *p, char dir)
{
	if (dir == 'N')
	{
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	if (dir == 'S')
	{
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
	if (dir == 'E')
	{
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	if (dir == 'W')
	{
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
}

void	set_player_direction(t_player *p, char dir)
{
	set_player_dir(p, dir);
	set_player_plane(p, dir);
}

int	validate_player_pos(t_tools *data, int x, int y)
{
	if (x <= 0 || y <= 0 || (size_t)x >= strlen(data->map[y]) - 1
		|| !data->map[y + 1])
		return (error("Error: Player is spawning out of bounds!"), 0);
	return (1);
}

int	find_player(t_tools *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (ft_strchr("NSEW", data->map[y][x]))
			{
				if (!validate_player_pos(data, x, y))
					return (0);
				data->player.pos_x = x + 0.5;
				data->player.pos_y = y + 0.5;
				set_player_direction(&data->player, data->map[y][x]);
				data->map[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (error("Error: No player start found in the map!"), 0);
}
