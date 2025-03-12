/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:13:47 by afayad            #+#    #+#             */
/*   Updated: 2025/03/10 21:04:43 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_image(t_tools *data, char *image_path, int delay)
{
	void	*img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	img = mlx_xpm_file_to_image(data->mlx, image_path, &img_width, &img_height);
	if (!img)
	{
		error("Failed to load splash screen image");
		return ;
	}
	x = (WIN_WIDTH - img_width) / 6;
	y = (WIN_HEIGHT - img_height) / 6;
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	usleep(delay);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, img);
}

void	display_splash_screen(t_tools *data)
{
	char	*image_paths[3];
	int		i;

	image_paths[0] = "./textures/cub.xpm";
	image_paths[1] = "./textures/loading.xpm";
	image_paths[2] = "./textures/move.xpm";
	i = 0;
	while (i < 3)
	{
		display_image(data, image_paths[i], 2000000);
		i++;
	}
}

static int	init_mlx(t_tools *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error("MLX Init Failed"), 1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		return (error("Window Creation Failed"), 1);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (error("Image Creation Failed"), 1);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	if (!data->addr)
		return (error("Data Address Retrieval Failed"), 1);
	return (0);
}

static int	setup_game(t_tools **data, char *map_file)
{
	memset(*data, 0, sizeof(t_tools));
	if (init_tools(data, map_file) == 0)
		return (cleanup_tools(data), 1);
	if (init_mlx(*data))
		return (1);
	(*data)->map = (*data)->map_matrix;
	if (!(*data)->map)
		return (error("Error: Map is NULL"), 1);
	if (!init_player(*data))
		return (1);
	load_textures(*data);
	return (0);
}

int	main(int ac, char **av)
{
	t_tools	*data;

	if (ac != 2)
		return (error("Usage: ./cub3D <map>"), 1);
	data = malloc(sizeof(t_tools));
	if (!data)
		return (error("Memory allocation failed"), 1);
	if (setup_game(&data, av[1]) == 1)
	{
		return (1);
	}
	display_splash_screen(data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 6, 1L << 6, mouse_move, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	free(data->mlx);
	cleanup_tools(&data);
	free(data);
	return (0);
}
