/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/17 13:55:54 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	coin(t_common *common)
{
	int	i;
	int	l;

	i = 0;
	while (common->game.s[i])
	{
		l = 0;
		while (common->game.s[i][l])
		{
			if (common->game.s[i][l] == 'C')
				return (0);
			l++;
		}
		i++;
	}
	return (1);
}

void	w_up(t_common *common)
{
	if (common->game.s[common->points.x - 1][common->points.y] == '1')
		return ;
	if (common->game.s[common->points.x - 1][common->points.y] == 'F')
	{
		common->binary = 0;
		fexit_plaer(common);
	}
	if (coin(common) == 1)
	{
		common->binary = 1;
		if (common->game.s[common->points.x - 1][common->points.y] == 'E')
			fexit_plaer(common);
	}
	else if (common->game.s[common->points.x][common->points.y] == 'E')
		return ;
	common->count++;
	common->game.s[common->points.x][common->points.y] = '0';
	common->game.s[common->ei][common->el] = 'E';
	common->game.s[common->points.x - 1][common->points.y] = 'P';
	common->points.x--;
}

void	a_left(t_common *common)
{
	if (common->game.s[common->points.x][common->points.y - 1] == '1')
		return ;
	if (common->game.s[common->points.x][common->points.y - 1] == 'F')
	{
		common->binary = 0;
		fexit_plaer(common);
	}
	if (coin(common) == 1)
	{
		common->binary = 1;
		if (common->game.s[common->points.x][common->points.y - 1] == 'E')
			fexit_plaer(common);
	}
	else if (common->game.s[common->points.x][common->points.y] == 'E')
		return ;
	common->count++;
	common->game.s[common->points.x][common->points.y] = '0';
	common->game.s[common->ei][common->el] = 'E';
	common->game.s[common->points.x][common->points.y - 1] = 'P';
	common->points.y--;
}

void	s_down(t_common *common)
{
	if (common->game.s[common->points.x + 1][common->points.y] == '1')
		return ;
	if (common->game.s[common->points.x + 1][common->points.y] == 'F')
	{
		common->binary = 0;
		fexit_plaer(common);
	}
	if (coin(common) == 1)
	{
		common->binary = 1;
		if (common->game.s[common->points.x + 1][common->points.y] == 'E')
			fexit_plaer(common);
	}
	else if (common->game.s[common->points.x][common->points.y] == 'E')
		return ;
	common->count++;
	common->game.s[common->points.x][common->points.y] = '0';
	common->game.s[common->ei][common->el] = 'E';
	common->game.s[common->points.x + 1][common->points.y] = 'P';
	common->points.x++;
}

void	d_right(t_common *common)
{
	if (common->game.s[common->points.x][common->points.y + 1] == '1')
		return ;
	if (common->game.s[common->points.x][common->points.y + 1] == 'F')
	{
		common->binary = 0;
		fexit_plaer(common);
	}
	if (coin(common) == 1)
	{
		common->binary = 1;
		if (common->game.s[common->points.x][common->points.y + 1] == 'E')
			fexit_plaer(common);
	}
	else if (common->game.s[common->points.x][common->points.y] == 'E')
		return ;
	common->count++;
	common->game.s[common->points.x][common->points.y] = '0';
	common->game.s[common->ei][common->el] = 'E';
	common->game.s[common->points.x][common->points.y + 1] = 'P';
	common->points.y++;
}
