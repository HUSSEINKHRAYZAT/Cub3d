/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:37:20 by afayad            #+#    #+#             */
/*   Updated: 2025/03/10 12:56:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	special_char(char c)
{
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		return (1);
	return (0);
}

int	check_ones(char *str)
{
	int	i;
	int	len;

	if (!str || !*str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	valid_line(char *str, int check)
{
	int	i;

	i = 0;
	if (check == 1)
	{
		while (str[i])
		{
			if (str[i] != '1')
				return (0);
			i++;
		}
	}
	else if (check == 0)
	{
		if (check_ones(str) == 0)
			return (0);
	}
	return (1);
}

int	valid_elements(char **map)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1'
					&& !special_char(map[i][j]))
				return (0);
			if (special_char(map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

int	valid_map(char **map)
{
	int	i;
	int	check;

	i = 0;
	if (count_double_ptr(map) < 2)
		return (0);
	while (map[i])
	{
		check = 0;
		if (i == 0 || i == (count_double_ptr(map) - 1))
			check = 1;
		if (valid_line(map[i], check) == 0)
			return (0);
		i++;
	}
	if (valid_elements(map) == 0 || check_algo(map) == 0)
		return (0);
	return (1);
}
