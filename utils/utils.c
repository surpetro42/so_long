/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/02 18:11:43 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	arrlen(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}
