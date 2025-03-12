/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:24:17 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/03/10 20:24:17 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_content(t_list *lst, char *check, int index)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		if (i == index)
		{
			if (ft_strncmp(temp->line, check, ft_strlen(check)) == 0)
				return (1);
			else
				return (0);
		}
		temp = temp->next;
		i++;
	}
	return (0);
}

int	check_filename(char *filename, int cub)
{
	int	len;
	int	fd;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if ((cub && ft_strcmp(filename + len - 4, ".xpm") != 0)
		|| (!cub && ft_strcmp(filename + len - 4, ".cub") != 0))
		return (0);
	fd = open(filename, O_RDONLY);
	if (cub && fd == -1)
		return (printf("Cannot read from the texture file\n"), 0);
	if (!cub && fd == -1)
		return (printf("Cannot read fromt the map file\n"), 0);
	close(fd);
	return (1);
}

int	parse_rgb_values(char *str, int *rgb)
{
	char	**parts;
	int		i;

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	i = 0;
	while (parts[i])
		i++;
	if (i != 3)
		return (free_array(parts), 0);
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(parts[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (free_array(parts), 0);
		i++;
	}
	free_array(parts);
	return (1);
}

char	*extract_path_from_list(t_list *list, int index, int skip_chars)
{
	t_list	*current;
	int		i;

	current = list;
	i = 0;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	if (!current || !current->line)
		return (NULL);
	return (ft_strskip(current->line, skip_chars));
}

int	*extract_color_from_list(t_list *list, int index)
{
	t_list	*current;
	int		i;
	char	*color_str;
	int		*color_array;

	current = list;
	i = 0;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	if (!current || !current->line)
		return (NULL);
	color_str = ft_strskip(current->line, 1);
	if (!color_str)
		return (NULL);
	color_array = (int *)malloc(3 * sizeof(int));
	if (!color_array)
		return (free(color_str), NULL);
	if (!parse_rgb_values(color_str, color_array))
		return (free(color_array), free(color_str), NULL);
	return (free(color_str), color_array);
}
