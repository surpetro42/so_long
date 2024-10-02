/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/10 17:25:13 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_xpm_image(t_common *common)
{
	int	w;
	int	h;

	w = 60;
	h = 60;
	common->imgs.grass = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/grass.xpm", &w, &h);
	common->imgs.wall = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/wall.xpm", &w, &h);
	common->imgs.plaer = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/plaer.xpm", &w, &h);
	common->imgs.mario = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/mario.xpm", &w, &h);
	common->imgs.marioanim = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/Manimation.xpm", &w, &h);
	common->imgs.exit_p = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/exit.xpm", &w, &h);
	common->imgs.opponent = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/opponent.xpm", &w, &h);
	common->imgs.fanim = mlx_xpm_file_to_image(common->mlx_ptr,
			"./image/Fanimation.xpm", &w, &h);
	if (!common->imgs.grass || !common->imgs.wall || !common->imgs.plaer
		|| !common->imgs.mario || !common->imgs.exit_p
		|| !common->imgs.opponent)
		exit(write(2, "Failed to load XPM image\n", 25));
}

void	mlx_xpm_game(t_common *common, void *win_ptr, char **s)
{
	common->game.mlx_ptr = common->mlx_ptr;
	common->game.win_ptr = win_ptr;
	common->game.s = s;
	common->game.img = &common->imgs;
}
