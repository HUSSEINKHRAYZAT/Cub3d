/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:59:22 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 19:02:53 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray, t_tools *data, int x)
{
	calculate_ray_direction(ray, data, x);
	init_map_coordinates(ray, data);
	calculate_delta_distances(ray);
	determine_step_and_side_distances(ray, data);
	init_hit_flag(ray);
}

void	perform_dda(t_ray *ray, t_tools *data, int map_width, int map_height)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= map_width || ray->map_y < 0
			|| ray->map_y >= map_height)
		{
			ray->hit = 1;
			continue ;
		}
		if (data->map[ray->map_y][ray->map_x] == '1')
		{
			ray->hit = 1;
		}
	}
}

void	calculate_wall_distance(t_ray *ray, t_tools *data)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - data->player.pos_x + (1
					- ray->step_x) / 2) / ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - data->player.pos_y + (1
					- ray->step_y) / 2) / ray->ray_dir_y;
	}
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	determine_texture_number(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
		{
			ray->tex_num = 3;
		}
		else
		{
			ray->tex_num = 2;
		}
	}
	else
	{
		if (ray->ray_dir_y > 0)
		{
			ray->tex_num = 1;
		}
		else
		{
			ray->tex_num = 0;
		}
	}
}
