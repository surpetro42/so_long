/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/11 17:41:05 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_buff_valid(char **s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	freearg(char **s)
{
	free_buff_valid(s);
	exit(write(2, "ERROR SPLIT\n", 12));
}
