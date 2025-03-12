/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:54:27 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 12:54:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_xpm_and_readable(char *filename)
{
	int	len;
	int	fd;

	if (!filename)
		return (printf("ERROR: Filename is NULL\n"), 0);
	len = strlen(filename);
	if (len < 4)
		return (0);
	if (strcmp(filename + len - 4, ".xpm") != 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	init_directions_helper(t_list *tmp_list, t_tools *tools, int check)
{
	if (check == 1)
	{
		if (!(check_content(tmp_list, "NO", 0) == 1
				&& check_content(tmp_list, "SO", 1) == 1
				&& check_content(tmp_list, "WE", 2) == 1
				&& check_content(tmp_list, "EA", 3) == 1
				&& check_content(tmp_list, "F", 4) == 1
				&& check_content(tmp_list, "C", 5) == 1))
			return (printf("EROOR: lines before the map!\n"), 0);
	}
	if (check == 2)
	{
		if (!check_xpm_and_readable(tools->no_path)
			|| !check_xpm_and_readable(tools->so_path)
			|| !check_xpm_and_readable(tools->we_path)
			|| !check_xpm_and_readable(tools->ea_path))
			return (printf("EROOR: lines before the map!\n"), 0);
	}
	return (1);
}

int	count_double_ptr(char **ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (0);
	while (ptr[count])
		count++;
	return (count);
}
