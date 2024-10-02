/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/14 17:12:05 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_keypress(int keycode, t_common *common)
{
	if (keycode == 53)
		fexit_plaer(common);
	else if (keycode == 13)
		w_up(common);
	else if (keycode == 0)
		a_left(common);
	else if (keycode == 1)
		s_down(common);
	else if (keycode == 2)
		d_right(common);
	return (0);
}

void	window(char **s)
{
	int			card_x;
	int			card_y;
	t_common	common;

	common.count = 0;
	card_y = len_y(s) * 60;
	card_x = len_x(s) * 60;
	common.mlx_ptr = mlx_init();
	if (common.mlx_ptr == NULL)
		exit(1 && write(2, "ERROR: mlx_init failed\n", 23));
	common.win_ptr = mlx_new_window(common.mlx_ptr,
			card_x, card_y, "My first window");
	mlx_xpm_image(&common);
	mlx_xpm_game(&common, common.win_ptr, s);
	mlx_loop_hook(common.mlx_ptr, map_img, &common);
	common.points = position(s);
	mlx_hook(common.win_ptr, 17, 0, &exitx, &common);
	mlx_hook(common.win_ptr, 2, 0, &handle_keypress, &common);
	mlx_loop(common.mlx_ptr);
	free(s);
}
