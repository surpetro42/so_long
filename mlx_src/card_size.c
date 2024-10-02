/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:10:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/04 13:51:34 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	len_x(char **s)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	if (!s || !*s)
		exit (0);
	while (s[i])
	{
		while (s[i][l])
			l++;
		i++;
	}
	return (l);
}

int	len_y(char **s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		exit (0);
	while (s[i])
		i++;
	return (i);
}
