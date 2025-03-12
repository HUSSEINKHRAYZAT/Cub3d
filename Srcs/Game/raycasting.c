/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:47:05 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 19:54:10 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(t_ray *ray, t_tools *data)
{
	if (ray->side == 0)
	{
		ray->wall_x = data->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	}
	else
	{
		ray->wall_x = data->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_texture_x(t_ray *ray, t_tools *data)
{
	ray->texx = (int)(ray->wall_x * data->texture.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1
			&& ray->ray_dir_y < 0))
	{
		ray->texx = data->texture.width - ray->texx - 1;
	}
	if (ray->texx < 0)
	{
		ray->texx = 0;
	}
	if (ray->texx >= data->texture.width)
	{
		ray->texx = data->texture.width - 1;
	}
}

void	determine_texture_coordinates(t_ray *ray, t_tools *data)
{
	determine_texture_number(ray);
	calculate_wall_x(ray, data);
	calculate_texture_x(ray, data);
}

void	cast_rays(t_tools *data)
{
	int		map_width;
	int		map_height;
	int		x;
	t_ray	ray;

	map_width = strlen(*data->map);
	map_height = 0;
	while (data->map[map_height])
		map_height++;
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(&ray, data, x);
		perform_dda(&ray, data, map_width, map_height);
		calculate_wall_distance(&ray, data);
		determine_texture_coordinates(&ray, data);
		draw_wall(&ray, data, x);
		x++;
	}
}
