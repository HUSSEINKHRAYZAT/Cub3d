/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:34:28 by afayad            #+#    #+#             */
/*   Updated: 2025/03/10 12:47:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_count2file(char *filename)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
		count++;
	close(fd);
	return (count);
}

char	*ft_readfile(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	size = ft_count2file(filename);
	if (size < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (read(fd, buffer, size) != size)
	{
		close(fd);
		free(buffer);
		return (NULL);
	}
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

static t_list	*ft_newnode(char *line)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

static void	ft_addback(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_file_to_list(char *content, int check)
{
	char	**lines;
	t_list	*list;
	t_list	*new;
	int		i;
	char	*line;

	lines = ft_split(content, '\n');
	list = NULL;
	i = 0;
	while (lines[i])
	{
		if (check == 0)
			line = ft_remove_spaces(lines[i]);
		else
			line = ft_strdup(lines[i]);
		if (line)
		{
			new = ft_newnode(line);
			if (new)
				ft_addback(&list, new);
		}
		free(lines[i]);
		i++;
	}
	return (free(lines), list);
}

// char	*ft_folder_maps(char *folder, char *str)
// {
// 	char	*new_str;
// 	int		len;

// 	if (!str || !folder)
// 		return (NULL);
// 	if (ft_strncmp(str, folder, strlen(folder)) == 0)
// 		return (strdup(str));
// 	len = strlen(folder) + strlen(str);
// 	new_str = (char *)malloc(sizeof(char) * (len + 2));
// 	if (!new_str)
// 		return (NULL);
// 	v_strcpy(new_str, folder);
// 	v_strcat(new_str, "/");
// 	v_strcat(new_str, str);
// 	return (new_str);
// }
