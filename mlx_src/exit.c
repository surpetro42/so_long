/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/17 13:57:43 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fexit_plaer(t_common *common)
{
	if (common->binary == 1)
		write(1, "Victory", 7);
	else if (common->binary == 0)
		write(2, "Game over", 10);
	mlx_destroy_image(common->mlx_ptr, common->imgs.exit_p);
	mlx_destroy_image(common->mlx_ptr, common->imgs.grass);
	mlx_destroy_image(common->mlx_ptr, common->imgs.mario);
	mlx_destroy_image(common->mlx_ptr, common->imgs.opponent);
	mlx_destroy_image(common->mlx_ptr, common->imgs.plaer);
	mlx_destroy_image(common->mlx_ptr, common->imgs.wall);
	free(common->game.s);
	exit(0);
}
