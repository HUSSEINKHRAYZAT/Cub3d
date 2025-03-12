/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:57:06 by afayad            #+#    #+#             */
/*   Updated: 2025/03/05 00:44:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines_list(t_list *list)
{
	int		count;
	t_list	*current;

	count = 0;
	current = list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_print_list(t_list *list)
{
	while (list)
	{
		printf("%s\n", list->line);
		list = list->next;
	}
}

char	*ft_strskip(char *str, size_t size)
{
	char	*result;
	size_t	len;

	if (!str || ft_strlen(str) == 0)
		return (NULL);
	str += size;
	while (*str && *str == ' ')
		str++;
	if (!*str)
		return (NULL);
	result = ft_strdup(str);
	if (!result)
		return (NULL);
	len = ft_strlen(result);
	while (len > 0 && result[len - 1] == ' ')
	{
		result[len - 1] = '\0';
		len--;
	}
	if (len == 0)
		return (free(result), NULL);
	return (result);
}

char	*ft_remove_spaces(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}
