/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/11 15:46:10 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	steps(t_common *common)
{
	char	*s;

	s = ft_itoa(common->count);
	if (!s)
	{
		fexit_plaer(common);
		perror("ERROR!");
	}
	mlx_string_put(common->mlx_ptr, common->win_ptr, 10, 10, 0xffffff, s);
	free(s);
}
