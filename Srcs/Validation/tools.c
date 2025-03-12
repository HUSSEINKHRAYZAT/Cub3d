/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:55:56 by afayad            #+#    #+#             */
/*   Updated: 2025/03/10 19:46:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player2(t_tools **tools)
{
	int	i;
	int	j;

	if (!(*tools) || !(*tools)->map_matrix)
		return (0);
	i = 0;
	while ((*tools)->map_matrix[i])
	{
		j = 0;
		while ((*tools)->map_matrix[i][j])
		{
			if ((*tools)->map_matrix[i][j] != '0'
					&& (*tools)->map_matrix[i][j] != '1')
			{
				(*tools)->player.pos_x = j;
				(*tools)->player.pos_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	init_tools(t_tools **tools, char *filename)
{
	init_null(tools);
	if (init_filetools(tools, filename) == 0)
		return (0);
	if (init_directions(tools) == 0)
		return (0);
	if (init_map(tools) == 0 || valid_map((*tools)->map_matrix) == 0)
		return (printf("the map is not valid\n"), 0);
	if (init_player2(tools) == 0)
		return (printf("the problem is here\n"), 0);
	return (1);
}

// for debug
	// print_double_ptr(tools->file_matrix);
	// ft_print_list(tools->list);
	// // printf("%s\n", tools->file_content);
	// printf("the no from deb: %s\n", tools->no_path);
	// printf("the so from deb: %s\n", tools->so_path);
	// printf("the we from deb: %s\n", tools->we_path);
	// printf("the ea from deb: %s\n", tools->ea_path);
	// printf("the player x is %d \n", tools->player.x);
	// printf("the player y is %d \n", tools->player.y);

int	init_directions(t_tools **tools)
{
	t_list	*tmp_list;

	if (!(*tools)->file_content)
		return (printf("File content is missing\n"), 0);
	tmp_list = ft_file_to_list((*tools)->file_content, 0);
	if (!init_directions_helper(tmp_list, *tools, 1))
		return (free_list(tmp_list), 0);
	(*tools)->no_path = extract_path_from_list(tmp_list, 0, 2);
	(*tools)->so_path = extract_path_from_list(tmp_list, 1, 2);
	(*tools)->we_path = extract_path_from_list(tmp_list, 2, 2);
	(*tools)->ea_path = extract_path_from_list(tmp_list, 3, 2);
	(*tools)->floor = extract_color_from_list(tmp_list, 4);
	(*tools)->back = extract_color_from_list(tmp_list, 5);
	if (!(*tools)->floor || !(*tools)->back)
		return (free_list(tmp_list),
			printf("The floor or back is missing\n"), 0);
	if (!init_directions_helper(tmp_list, *tools, 2))
		return (free_list(tmp_list), 0);
	free_list(tmp_list);
	return (1);
}

int	init_filetools(t_tools **tools, char *filename)
{
	if (check_filename(filename, 0) == 0)
		return (printf("This file not '.cub'\n"), 0);
	(*tools)->map_path = ft_strdup(filename);
	(*tools)->file_content = ft_readfile((*tools)->map_path);
	if (!(*tools)->file_content)
		return (printf("Error: Could not read the file\n"), 0);
	(*tools)->list = ft_file_to_list((*tools)->file_content, 1);
	(*tools)->file_matrix = ft_split((*tools)->file_content, '\n');
	return (1);
}

int	init_map(t_tools **tools)
{
	t_list	*current;
	int		line_count;
	int		i;

	current = (*tools)->list;
	i = 0;
	while (i < 6 && current)
	{
		current = current->next;
		i++;
	}
	if (i < 6)
		return (0);
	line_count = count_lines_list(current);
	(*tools)->map_matrix = malloc((line_count + 1) * sizeof(char *));
	(*tools)->map_matrix[line_count] = NULL;
	i = 0;
	while (current)
	{
		(*tools)->map_matrix[i] = ft_strdup(current->line);
		current = current->next;
		i++;
	}
	replace_spaces(*tools);
	return (1);
}
