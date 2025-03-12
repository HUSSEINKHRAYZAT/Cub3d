/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:58:34 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/10 20:23:43 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_direction(t_ray *ray, t_tools *data, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
}

void	init_map_coordinates(t_ray *ray, t_tools *data)
{
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
}

void	calculate_delta_distances(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
	{
		ray->delta_dist_x = 1e30;
	}
	else
	{
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	}
	if (ray->ray_dir_y == 0)
	{
		ray->delta_dist_y = 1e30;
	}
	else
	{
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	}
}

void	determine_step_and_side_distances(t_ray *ray, t_tools *data)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	init_hit_flag(t_ray *ray)
{
	ray->hit = 0;
}
