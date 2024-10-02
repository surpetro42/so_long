/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:37:22 by surpetro          #+#    #+#             */
/*   Updated: 2024/06/02 17:23:32 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	x;
	size_t	y;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	x = 0;
	y = ft_strlen(s1);
	while (s1[x] && ft_strchr(set, s1[x]))
		x++;
	while (y > x && ft_strchr(set, s1[y - 1]))
		y--;
	trimmed_str = ft_substr(s1, x, y - x);
	return (trimmed_str);
}
