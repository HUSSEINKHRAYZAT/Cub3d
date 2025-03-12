/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:24:40 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/10 20:24:40 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_null(t_tools **tools)
{
	(*tools)->file_matrix = NULL;
	(*tools)->map_matrix = NULL;
	(*tools)->map_path = NULL;
	(*tools)->no_path = NULL;
	(*tools)->so_path = NULL;
	(*tools)->we_path = NULL;
	(*tools)->ea_path = NULL;
	(*tools)->file_content = NULL;
	(*tools)->floor = NULL;
	(*tools)->back = NULL;
	(*tools)->list = NULL;
	(*tools)->player.pos_x = 0;
	(*tools)->player.pos_y = 0;
}

void	free_tools_data(t_tools *tools)
{
	free_matrix(tools->map_matrix);
	free_matrix(tools->file_matrix);
	if (tools->map)
		free_map(tools->map);
	if (tools->file_content)
		free(tools->file_content);
	if (tools->no_path)
		free(tools->no_path);
	if (tools->so_path)
		free(tools->so_path);
	if (tools->we_path)
		free(tools->we_path);
	if (tools->ea_path)
		free(tools->ea_path);
	if (tools->map_path)
		free(tools->map_path);
	if (tools->gun_addr)
		free(tools->gun_addr);
	if (tools->floor)
		free(tools->floor);
	if (tools->back)
		free(tools->back);
	if (tools->list)
		free_list(tools->list);
}

void	free_mlx_resources(t_tools *tools)
{
	if (tools->img)
		mlx_destroy_image(tools->mlx, tools->img);
	if (tools->gun_img)
		mlx_destroy_image(tools->mlx, tools->gun_img);
	if (tools->win)
		mlx_destroy_window(tools->mlx, tools->win);
	if (tools->mlx)
	{
		mlx_destroy_display(tools->mlx);
		free(tools->mlx);
	}
}

void	cleanup_tools(t_tools **tools)
{
	if (!tools || !(*tools))
		return ;
	free_tools_data(*tools);
	free_mlx_resources(*tools);
	free(*tools);
}
