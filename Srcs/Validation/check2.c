/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:24:26 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/10 20:24:26 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_adjacent(char **str, int x, int y)
{
	if (!str[x + 1] || str[x + 1][y + 1] == '\0')
		return (0);
	if (!str[x + 1])
		return (0);
	if (str[x][y + 1] == '\0')
		return (0);
	if (x - 1 >= 0 && y - 1 >= 0)
	{
		if (!str[x - 1] || str[x - 1][y - 1] == '\0')
			return (0);
	}
	if (x - 1 >= 0 && !str[x - 1])
		return (0);
	if (y - 1 >= 0 && str[x][y - 1] == '\0')
		return (0);
	return (1);
}

int	check_string_position(char **str, int x, int y)
{
	if (!str || !str[x] || str[x][y] == '\0')
		return (0);
	return (check_adjacent(str, x, y));
}

int	check_algo(char **map)
{
	int	x;
	int	y;

	if (!map)
		return (0);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '1' && !check_string_position(map, x, y))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	replace_spaces(t_tools *tools)
{
	int		i;
	int		j;
	char	*str;

	if (tools == NULL || tools->map_matrix == NULL)
		return ;
	i = 0;
	while (tools->map_matrix[i] != NULL)
	{
		str = tools->map_matrix[i];
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == 32 || (str[j] >= 9 && str[j] <= 13))
				str[j] = '1';
			j++;
		}
		i++;
	}
}
