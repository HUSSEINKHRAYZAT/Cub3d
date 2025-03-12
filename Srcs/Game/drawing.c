/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:49:35 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/09 16:49:36 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_frame(t_tools *data)
{
	clear_image(data);
	draw_floor_and_sky(data);
	cast_rays(data);
	update_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw_transparent_gun(data);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

int	game_loop(t_tools *data)
{
	render_frame(data);
	return (0);
}

void	put_pixel_to_image(t_tools *data, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		*(int *)(data->addr + (y * data->line_length + x * (data->bpp
						/ 8))) = color;
}

int	load_single_texture(t_tools *data, char *path, int i)
{
	data->texture.img[i] = mlx_xpm_file_to_image(data->mlx, path,
			&data->texture.width, &data->texture.height);
	if (!data->texture.img[i])
		return (error("Error: One or more textures failed to load."), 1);
	data->texture.address[i] = mlx_get_data_addr(data->texture.img[i],
			&data->texture.bpp, &data->texture.line_length,
			&data->texture.endian);
	return (0);
}

void	load_textures(t_tools *data)
{
	int		i;
	char	*paths[4];

	paths[0] = data->no_path;
	paths[1] = data->so_path;
	paths[2] = data->we_path;
	paths[3] = data->ea_path;
	i = -1;
	while (++i < 4)
		if (load_single_texture(data, paths[i], i))
			return ;
	data->gun_img = mlx_xpm_file_to_image(data->mlx, "./textures/gun.xpm",
			&data->gun_width, &data->gun_height);
	if (!data->gun_img)
		error("Error: Gun texture failed to load.");
	data->gun_addr = mlx_get_data_addr(data->gun_img, &data->gun_bpp,
			&data->gun_line_length, &data->gun_endian);
}
