/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/17 13:47:22 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	grass(t_common *commno)
{
	int	i;
	int	l;

	i = 0;
	while (commno->game.s[i])
	{
		l = 0;
		while (commno->game.s[i][l])
		{
			mlx_put_image_to_window(commno->game.mlx_ptr,
				commno->game.win_ptr,
				commno->game.img->grass, (l * 60), (i * 60));
			l++;
		}
		i++;
	}
}

void	plaer_exit(t_common *common)
{
	int	i;
	int	l;

	i = 0;
	while (common->game.s[i])
	{
		l = 0;
		while (common->game.s[i][l])
		{
			if (common->game.s[i][l] == 'P')
				mlx_put_image_to_window(common->game.mlx_ptr,
					common->game.win_ptr,
					common->game.img->plaer, (l * 60), (i * 60));
			if (common->game.s[i][l] == 'E')
			{
				common->ei = i;
				common->el = l;
				mlx_put_image_to_window(common->game.mlx_ptr,
					common->game.win_ptr,
					common->game.img->exit_p, (l * 60), (i * 60));
			}
			l++;
		}
		i++;
	}
}

void	coin_opponent(t_common *common, int v_a)
{
	int	i;
	int	l;
	int	count;

	i = 0;
	l = 0;
	count = 0;
	while (common->game.s[i])
	{
		l = 0;
		while (common->game.s[i][l])
		{
			common->i = i;
			common->l = l;
			animation_coin(common, common->game.s[i][l], v_a);
			l++;
		}
		i++;
	}
}

void	wall(t_common *common)
{
	int			i;
	int			l;

	i = 0;
	l = 0;
	while (common->game.s[i])
	{
		l = 0;
		while (common->game.s[i][l])
		{
			if (common->game.s[i][l] == '1')
				mlx_put_image_to_window(common->game.mlx_ptr,
					common->game.win_ptr,
					common->game.img->wall, (l * 60), (i * 60));
			l++;
		}
		i++;
	}
}

int	map_img(t_common *common)
{
	static int	v_a;

	if (v_a > 100)
		v_a = 0;
	v_a++;
	grass(common);
	plaer_exit(common);
	coin_opponent(common, v_a);
	wall(common);
	steps(common);
	return (0);
}
