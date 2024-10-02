/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/14 18:02:04 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	position(char **s)
{
	t_point	pos;
	int		i;
	int		l;

	pos.x = -1;
	pos.y = -1;
	i = 0;
	while (s[i])
	{
		l = 0;
		while (s[i][l])
		{
			if (s[i][l] == 'P')
			{
				pos.x = i;
				pos.y = l;
				return (pos);
			}
			l++;
		}
		i++;
	}
	free(s);
	exit(write(2, "DE hima ERROR\n", 14));
}

void	fill(char **map, t_point size_map, t_point pos)
{
	if (pos.x < 0 || pos.x >= size_map.x || pos.y < 0 || pos.y >= size_map.y
		|| (map[pos.x][pos.y] != 'P' && map[pos.x][pos.y] != '0'
		&& map[pos.x][pos.y] != 'C' && map[pos.x][pos.y] != 'E'))
		return ;
	map[pos.x][pos.y] = '-';
	fill(map, size_map, (t_point){pos.x - 1, pos.y});
	fill(map, size_map, (t_point){pos.x + 1, pos.y});
	fill(map, size_map, (t_point){pos.x, pos.y - 1});
	fill(map, size_map, (t_point){pos.x, pos.y + 1});
}

void	flood_fill(char **s)
{
	t_point	size_map;
	t_point	pos;

	size_map.x = arrlen(s);
	size_map.y = ft_strlen(s[0]);
	pos = position(s);
	fill(s, size_map, pos);
	check_from_flood(s);
}

void	check_from_flood(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'E')
			{
				free(map);
				exit(write(2, "ERROR\nCANT WIN!\n", 16));
			}
			x++;
		}
		y++;
	}
}
