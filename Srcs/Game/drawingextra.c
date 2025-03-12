/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawingextra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:28:57 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 17:14:10 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_and_sky(t_tools *data)
{
	int	x;
	int	y;
	int	sky_color;
	int	floor_clr;

	sky_color = (data->back[0] << 16) | (data->back[1] << 8) | data->back[2];
	floor_clr = (data->floor[0] << 16) | (data->floor[1] << 8) | data->floor[2];
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				put_pixel_to_image(data, x, y, sky_color);
			else
				put_pixel_to_image(data, x, y, floor_clr);
		}
	}
}

void	draw_gun_pixel(t_tools *data, t_point *gun, t_point *offset)
{
	int		pixel_offset;
	char	*pixel_ptr;
	int		pixel_color;

	pixel_offset = (offset->y * data->gun_line_length) + (offset->x
			* (data->gun_bpp / 8));
	pixel_ptr = data->gun_addr + pixel_offset;
	pixel_color = *(int *)pixel_ptr;
	if (((pixel_color >> 16) & 0xFF) || ((pixel_color >> 8) & 0xFF)
		|| (pixel_color & 0xFF))
		put_pixel_to_image(data, gun->x + offset->x, gun->y + offset->y,
			pixel_color);
}

void	draw_transparent_gun(t_tools *data)
{
	t_point	offset;
	t_point	gun;

	if (!data->gun_img || !data->gun_addr)
		return ;
	gun.x = WIN_WIDTH / 2 - data->gun_width / 2;
	gun.y = WIN_HEIGHT - data->gun_height - 10;
	offset.y = -1;
	while (++offset.y < data->gun_height)
	{
		offset.x = -1;
		while (++offset.x < data->gun_width)
			draw_gun_pixel(data, &gun, &offset);
	}
}
