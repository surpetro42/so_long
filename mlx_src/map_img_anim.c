/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_img_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/11 15:45:15 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animation_coin(t_common *common, char c, int v_a)
{
	if (c == 'C')
	{
		if (v_a <= 50)
			mlx_put_image_to_window(common->game.mlx_ptr,
				common->game.win_ptr,
				common->game.img->mario, (common->l * 60), (common->i * 60));
		else if (v_a > 50)
			mlx_put_image_to_window(common->game.mlx_ptr,
				common->game.win_ptr,
				common->game.img->marioanim,
				(common->l * 60), (common->i * 60));
	}
	else if (c == 'F')
	{
		if (v_a <= 50)
			mlx_put_image_to_window(common->game.mlx_ptr,
				common->game.win_ptr,
				common->game.img->opponent, (common->l * 60), (common->i * 60));
		else if (v_a > 50)
			mlx_put_image_to_window(common->game.mlx_ptr,
				common->game.win_ptr,
				common->game.img->fanim, (common->l * 60), (common->i * 60));
	}
}
