/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:28:28 by afayad            #+#    #+#             */
/*   Updated: 2025/03/04 15:28:08 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	const char	*copy;
	char		*result;
	size_t		i;

	i = 0;
	copy = src;
	result = dest;
	while (i < n)
	{
		result[i] = copy[i];
		i++;
	}
	return (result);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		if (src_len < size - 1)
		{
			copy_len = src_len;
		}
		else
			copy_len = size - 1;
		ft_memcpy(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return (src_len);
}

int	is_all_digits(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	print_double_ptr(char **args)
{
	int	i;

	if (args[0] == NULL)
	{
		printf("its null!\n");
		return ;
	}
	i = 0;
	while (args[i] != NULL)
	{
		printf("%s\n", args[i]);
		i++;
	}
}
