/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:14:15 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 19:55:03 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_texture_y(t_ray *ray, t_tools *data, int y)
{
	int	d;

	d = (y - WIN_HEIGHT / 2 + ray->line_height / 2) * 256;
	ray->texy = ((d * data->texture.height) / ray->line_height) / 256;
	if (ray->texy < 0)
	{
		ray->texy = 0;
	}
	if (ray->texy >= data->texture.height)
	{
		ray->texy = data->texture.height - 1;
	}
}

long int	get_texture_color(t_ray *ray, t_tools *data)
{
	uint32_t	*texture_pixels;

	if (!data->texture.address[ray->tex_num])
	{
		printf("Texture address for %d is NULL!\n", ray->tex_num);
		return (0);
	}
	texture_pixels = (uint32_t *)data->texture.address[ray->tex_num];
	return (texture_pixels[data->texture.width * ray->texy + ray->texx]);
}

void	draw_vertical_line(t_ray *ray, t_tools *data, int x)
{
	int			y;
	long int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		calculate_texture_y(ray, data, y);
		color = get_texture_color(ray, data);
		put_pixel_to_image(data, x, y, color);
		y++;
	}
}

void	draw_wall(t_ray *ray, t_tools *data, int x)
{
	draw_vertical_line(ray, data, x);
}
